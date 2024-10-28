#include "stm32f10x.h"                  // Device header
#include "IIC.h"
#include "Delay.h"
#define DataSize_8x16 16
#define DataSize_8x6 6
#define Pad_Fill 1
#define Pad_NoFill 0
#include "MYOLED_Data.h"
#include <String.h>
/*
	注：调用此文件的任何显示函数之后都需要调用显示更新函数也就是MYOLEDPLUS_UpData();
	否则无法显示
*/
typedef struct Ch{
	uint8_t top[3];
	uint8_t ARR[32];
}chinese;
extern chinese arr_chinese8x16[];
/*
	此函数用于写命令
*/
void MYOLEDPLUS_WCommand(uint8_t Command){
	IIC_Start();
	MyI2C_SendByte(0x78);
	//接受应答
	MyI2C_ReadAck();
	//发送控制字节 非连续模式命令字节
	MyI2C_SendByte(0x00);
	//接受应答
	MyI2C_ReadAck();
	MyI2C_SendByte(Command);
	//接受应答
	MyI2C_ReadAck();
	IIC_Stop();

}

/*
	此函数用于写数据
*/
void MYOLEDPLUS_WData(uint8_t Data[],uint8_t count){
	IIC_Start();
	MyI2C_SendByte(0x78);
	//接受应答
	MyI2C_ReadAck();
	//发送控制字节 非连续模式数据字节
	MyI2C_SendByte(0x40);
	//接受应答
	MyI2C_ReadAck();
	for(uint8_t i=0;i<count;i++){
	MyI2C_SendByte(Data[i]);
	//接受应答
	MyI2C_ReadAck();
	}
	IIC_Stop();
}

/*
	初始化OLED函数
	使用其他函数之前应先调用该函数
*/
void MYOLEDPLUS_Init(void){
	//IIC初始化
	IIC_Init();
	Delay_ms(100);
	//发送命令 关闭显示
	MYOLEDPLUS_WCommand(0XAE);
	//设置时钟分频比/振荡器频率
	MYOLEDPLUS_WCommand(0XD5);	
	MYOLEDPLUS_WCommand(0X80);
	
	//设置多路复用比率
	MYOLEDPLUS_WCommand(0XA8);
	MYOLEDPLUS_WCommand(0X3F);
	
	//设置显示偏移量
	MYOLEDPLUS_WCommand(0XD3);
	MYOLEDPLUS_WCommand(0X00);
	//设置显示起始线
	MYOLEDPLUS_WCommand(0X40);
	//设置段重映射
	MYOLEDPLUS_WCommand(0XA1);
	//设置COM输出扫描方向
	MYOLEDPLUS_WCommand(0XC8);	
	//设置COM引脚硬件配置
	MYOLEDPLUS_WCommand(0XDA);
	MYOLEDPLUS_WCommand(0X12);
	//设置对比度设置
	MYOLEDPLUS_WCommand(0X81);
	MYOLEDPLUS_WCommand(0XCF);
	//设置预充期
	MYOLEDPLUS_WCommand(0XD9);
	MYOLEDPLUS_WCommand(0XF1);
	//设置VCOMH取消电平
	MYOLEDPLUS_WCommand(0XDB);
	MYOLEDPLUS_WCommand(0X30);
	//恢复到RAM显示
	MYOLEDPLUS_WCommand(0XA4);
	//设置正向显示
	MYOLEDPLUS_WCommand(0XA6);
	//设置充电泵
	MYOLEDPLUS_WCommand(0X8D);
	MYOLEDPLUS_WCommand(0X14);
	//设置显示打开
	MYOLEDPLUS_WCommand(0XAF);
	
}

/*
	此函数用于设置显示的起始位置
	row：0~7
	col：0~63
*/
void MYOLEDPLUS_SetLocation(uint8_t row,uint8_t col){
	//设置行
	MYOLEDPLUS_WCommand(0xB0|row);
	//设置列
	MYOLEDPLUS_WCommand(0x10|((col&0xf0)>>4));
	MYOLEDPLUS_WCommand(0x00|(col&0x0f));


}

/*
	该函数用于将缓存数组更新到显示屏上
*/
void MYOLEDPLUS_UpData(void){
	for(uint16_t i=0;i<8;i++){
	MYOLEDPLUS_SetLocation(i,0);
	MYOLEDPLUS_WData(arr_main[i],128);
	}
}

/*
	该函数用于清屏
*/
void MYOLEDPLUS_Clear(void){
	for(uint8_t j=0;j<8;j++){
	MYOLEDPLUS_SetLocation(j,0);
	MYOLEDPLUS_WData(arr_clear[j],1);
	}
}

/*
	此函数用于清出区域显示
*/
void MYOLEDPLUS_ClearArea(uint8_t x,uint8_t y,uint8_t length,uint8_t width){
	for(uint8_t i=y;i<=y+width;i++){
		for(uint8_t j=x;j<=x+length;j++){
			arr_main[i/8][j]&=~(0x01<<(i%8));
		}
	}
}

/*
	此函数用于显示图像
	x取值范围是0~127
	y取值范围是0~63
	length取值范围是0~127
	width取值范围为0~63
	arr为取模软件生成的数组
*/
void MYOLEDPLUS_ShowImage(uint8_t x,uint8_t y,uint8_t length,uint8_t width,const uint8_t arr[]){
	MYOLEDPLUS_ClearArea(x,y,length,width);
	for(uint8_t j=0;j<(width-1)/8+1;j++){
		for(uint8_t i=0;i<length;i++){
		arr_main[y/8+j][x+i]|=arr[j*length+i]<<(y%8);
		arr_main[y/8+1+j][x+i]|=arr[j*length+i]>>(8-y%8);
		}
	}
}

/*
	此函数用于显示字符
	x取值范围是0~127
	y取值范围是0~63
	Char的取值范围是ascii表中的可视字符
	DataSize： DataSize_8x16 DataSize_8x6
*/
void MYOLEDPLUS_ShowChar(uint8_t x,uint8_t y,char Char,uint8_t DataSize){
	if(DataSize==DataSize_8x16){
		MYOLEDPLUS_ClearArea(x,y,8,16);
		MYOLEDPLUS_ShowImage(x,y,8,16,arr_char8x16[Char-32]);
	}
	if(DataSize==DataSize_8x6){
		MYOLEDPLUS_ClearArea(x,y,6,8);
		MYOLEDPLUS_ShowImage(x,y,6,8,arr_char8x6[Char-32]);
	}
}

/*
	此函数用于显示字符串
	x取值范围是0~127
	y取值范围是0~63
	Str为需要显示的字符串
	DataSize： DataSize_8x16 DataSize_8x6
*/
void MYOLEDPLUS_ShowString(uint8_t x,uint8_t y,char* Str,uint8_t DataSize){
	uint8_t i=0;
	if(DataSize==DataSize_8x16){
		while(*Str!='\0'){
		MYOLEDPLUS_ClearArea(x+8*i,y,8,16);
		MYOLEDPLUS_ShowImage(x+8*i,y,8,16,arr_char8x16[*Str-32]);
		Str++;
		i++;
		}
	}
	if(DataSize==DataSize_8x6){
		while(*Str!='\0'){
		MYOLEDPLUS_ClearArea(x+8*i,y,6,8);
		MYOLEDPLUS_ShowImage(x+8*i,y,6,8,arr_char8x6[*Str-32]);
		Str++;
		i++;
		}
	}
}

/*
	此函数用于获取x的y次方
*/
uint32_t POW(int8_t x,int8_t y){
	uint32_t temp=1;
	while(y--){
		temp*=x;
	}
	return temp;
}

/*
	此函数用于显示无符号数字=
	x取值范围是0~127
	y取值范围是0~63
	Num：0~4,294,967,295
	length为想要显示的长度
	DataSize： DataSize_8x16 DataSize_8x6
*/
void MYOLEDPLUS_ShowNum(uint8_t x,uint8_t y,uint32_t Num,uint8_t length,uint8_t DataSize){
	uint8_t i=0;
	if(DataSize==DataSize_8x16){
		while(length--){
		MYOLEDPLUS_ClearArea(x+8*i,y,8,16);
		MYOLEDPLUS_ShowImage(x+8*i,y,8,16,arr_char8x16[(Num/POW(10,length)%10)+16]);
		i++;
		}
	}
	if(DataSize==DataSize_8x6){
		while(length--){
		MYOLEDPLUS_ClearArea(x+8*i,y,6,8);
		MYOLEDPLUS_ShowImage(x+8*i,y,6,8,arr_char8x6[(Num/POW(10,length)%10)+16]);
		i++;
		}
	}
}

/*
	此函数用于显示有符号整数
	x取值范围是0~127
	y取值范围是0~63
	Num：-2,147,483,648~2,147,483,647
	length为想要显示的长度
	DataSize： DataSize_8x16 DataSize_8x6
*/
void MYOLEDPLUS_ShowSignedNum(uint8_t x,uint8_t y,int Num,uint8_t length,uint8_t DataSize){
	uint8_t i=0;
	if(Num>=0){
	if(DataSize==DataSize_8x16){
		while(length--){
		MYOLEDPLUS_ClearArea(x+8*i,y,8,16);
		MYOLEDPLUS_ShowImage(x+8*i,y,8,16,arr_char8x16[(Num/POW(10,length)%10)+16]);
		i++;
		}
	}
	if(DataSize==DataSize_8x6){
		while(length--){
		MYOLEDPLUS_ClearArea(x+8*i,y,6,8);
		MYOLEDPLUS_ShowImage(x+8*i,y,6,8,arr_char8x6[(Num/POW(10,length)%10)+16]);
		i++;
		}
	}
	}
	else{
		Num=-Num;
		if(DataSize==DataSize_8x16){
		MYOLEDPLUS_ClearArea(x,y,8,16);
		MYOLEDPLUS_ShowImage(x,y,8,16,arr_char8x16[13]);
		while(length--){
		MYOLEDPLUS_ClearArea(x+8*(i+1),y,8,16);
		MYOLEDPLUS_ShowImage(x+8*(i+1),y,8,16,arr_char8x16[(Num/POW(10,length)%10)+16]);
		i++;
		}
	}
	if(DataSize==DataSize_8x6){
		MYOLEDPLUS_ClearArea(x,y,6,8);
		MYOLEDPLUS_ShowImage(x,y,6,8,arr_char8x6[13]);
		while(length--){
		MYOLEDPLUS_ClearArea(x+8*(i+1),y,6,8);
		MYOLEDPLUS_ShowImage(x+8*(i+1),y,6,8,arr_char8x6[(Num/POW(10,length)%10)+16]);
		i++;
		}
	}
	}
}

/*
	此函数用于显示二进制数
	x取值范围是0~127
	y取值范围是0~63
	Num：0~4,294,967,295
	length为想要显示的长度
	DataSize： DataSize_8x16 DataSize_8x6
*/
void MYOLEDPLUS_ShowBinNum(uint8_t x,uint8_t y,uint32_t Num,uint8_t length,uint8_t DataSize){
	uint8_t i=0;
	uint8_t arr_bin[32];
	if(DataSize==DataSize_8x16){
		for(uint8_t j=0;j<32;j++){
			if(Num%2==0){
				arr_bin[j]=0;
			}
			if(Num%2==1){
				arr_bin[j]=1;
			}
			Num/=2;	
		}
		while(length--){
			MYOLEDPLUS_ClearArea(x+8*i,y,8,16);
			MYOLEDPLUS_ShowImage(x+8*i,y,8,16,arr_char8x16[arr_bin[length]+16]);
			i++;
		}
	}
	if(DataSize==DataSize_8x6){
		for(uint8_t j=0;j<32;j++){
			if(Num%2==0){
				arr_bin[j]=0;
			}
			if(Num%2==1){
				arr_bin[j]=1;
			}
			Num/=2;	
		}
		while(length--){
			MYOLEDPLUS_ClearArea(x+8*i,y,6,8);
			MYOLEDPLUS_ShowImage(x+8*i,y,6,8,arr_char8x6[arr_bin[length]+16]);
			i++;
		}
	}
	
}

/*
	此函数用于显示十六进制数
	x取值范围是0~127
	y取值范围是0~63
	Num：0~4,294,967,295
	length为想要显示的长度
	DataSize： DataSize_8x16 DataSize_8x6
*/
void MYOLEDPLUS_ShowHexNum(uint8_t x,uint8_t y,uint32_t Num,uint8_t length,uint8_t DataSize){
	uint8_t i;
	uint8_t arr_hex[8];
	if(DataSize==DataSize_8x16){
		for(uint8_t j=0;j<8;j++){
			if(Num%16==10){arr_hex[j]='A';}
			else if(Num%16==11){arr_hex[j]='B';}
			else if(Num%16==12){arr_hex[j]='C';}
			else if(Num%16==13){arr_hex[j]='D';}
			else if(Num%16==14){arr_hex[j]='E';}
			else if(Num%16==15){arr_hex[j]='F';}
			else arr_hex[j]=Num%16;
			Num/=16;
		}
		while(length--){
			MYOLEDPLUS_ClearArea(x+8*i,y,8,16);
			if(arr_hex[length]>=0&&arr_hex[length]<=9){
			MYOLEDPLUS_ShowImage(x+8*i,y,8,16,arr_char8x16[arr_hex[length]+16]);
			}
			if(arr_hex[length]>='A'&&arr_hex[length]<='F'){
			MYOLEDPLUS_ShowImage(x+8*i,y,8,16,arr_char8x16[arr_hex[length]-32]);
			}
			i++;
	}
	}
	if(DataSize==DataSize_8x6){
		for(uint8_t j=0;j<8;j++){
			if(Num%16==10){arr_hex[j]='A';}
			else if(Num%16==11){arr_hex[j]='B';}
			else if(Num%16==12){arr_hex[j]='C';}
			else if(Num%16==13){arr_hex[j]='D';}
			else if(Num%16==14){arr_hex[j]='E';}
			else if(Num%16==15){arr_hex[j]='F';}
			else arr_hex[j]=Num%16;
			Num/=16;
		}
		while(length--){
			MYOLEDPLUS_ClearArea(x+8*i,y,6,8);
			if(arr_hex[length]>=0&&arr_hex[length]<=9){
			MYOLEDPLUS_ShowImage(x+8*i,y,6,8,arr_char8x6[arr_hex[length]+16]);
			}
			if(arr_hex[length]>='A'&&arr_hex[length]<='F'){
			MYOLEDPLUS_ShowImage(x+8*i,y,6,8,arr_char8x6[arr_hex[length]-32]);
			}
			i++;
	}
	}
}

/*
	此函数用于点亮一个点
	x取值范围：0~127
	y取值范围：0~63
*/
void MYOLEDPLUS_LightUpDot(uint8_t x,uint8_t y){
	arr_main[y/8][x]|=0x01<<(y%8);
}

/*
	此函数用于熄灭一个点
	x取值范围：0~127
	y取值范围：0~63
*/
void MYOLEDPLUS_LightDownDot(uint8_t x,uint8_t y){
	arr_main[y/8][x]&=~(0x01<<(y%8));
}

/*
	此函数用于画矩形
	x取值范围：0~127
	y取值范围：0~63
	length:0~127
	width:0~63
	Pad:Pad_Fill :内部填充
		Pad_NoFill:内部不填充
*/
void MYOLEDPLUS_LightUpRec(uint8_t x,uint8_t y,uint8_t length ,uint8_t width,uint8_t Pad){
	MYOLEDPLUS_ClearArea(x,y,length,width);
	if(Pad==Pad_Fill){
	for(uint8_t i=x;i<=x+length;i++){
		for(uint8_t j=y;j<=y+width;j++){
			MYOLEDPLUS_LightUpDot(i,j);
		}
	}
	}
	if(Pad==Pad_NoFill){
		for(uint8_t i=x;i<=x+length;i++){
		for(uint8_t j=y;j<=y+width;j++){
			if(i==x||j==y||i==x+length||j==y+width){
			MYOLEDPLUS_LightUpDot(i,j);
			}
		}
	}
	}
}

/*
	此函数用于画直线
	x，x1取值范围：0~127
	y，y1取值范围：0~63
	第一个点的坐标为（x，y）
	第二个点的坐标为（x1，y1）
*/
void MYOLEDPLUS_ShowLine(uint8_t x,uint8_t y,uint8_t x1,uint8_t y1){
	float k=(float)(y1-y)/(x1-x);
	for(uint8_t i=x;i<=x1;i++){
		MYOLEDPLUS_LightUpDot(i,y+k*(i-x));
	}
}

/*
	此函数为画圆函数 但是由于算法与设备以及参数等问题所画的圆并不是完美的圆
	x，x1取值范围：0~127
	y，y1取值范围：0~63
	圆心坐标（x，y）；
	radius为半径
*/
void MYOLEDPLUS_ShowRound(uint8_t x,uint8_t y,uint8_t radius,uint8_t Pad){
	if(Pad==Pad_NoFill){
	for(uint8_t i=x-radius;i<=x+radius;i++){
		for(uint8_t j=y-radius;j<=y+radius;j++){
			if(POW((i-x),2)+POW((j-y),2)==POW(radius,2)){
//				if(i>=0&&i<=127&&j>=0&&j<=63){
					MYOLEDPLUS_LightUpDot(i,j);
//				}
			}
		}
	}
	}
	if(Pad==Pad_Fill){
		uint8_t temp=0;
		for(uint8_t i=x-radius;i<=x+radius;i++){
		for(uint8_t j=y-radius;j<=y+radius;j++){
			if(i==x-radius||i==x+radius){
			if(POW((i-x),2)+POW((j-y),2)==POW(radius,2)){MYOLEDPLUS_LightUpDot(i,j);};
			}
			else{
			if(POW((i-x),2)+POW((j-y),2)==POW(radius,2)){
				temp++;
				temp%=2;
			}
			if(temp==1){
				MYOLEDPLUS_LightUpDot(i,j);
			}
		}
	}
	}
	}
}

/*
	此函数用于显示中文
	x取值范围：0~127
	y取值范围：0~63
	Str是中文字符串
*/
void MYOLEDPLUS_ShowChinese(uint8_t x,uint8_t y,char* Str){
	uint8_t temp=0;
	uint8_t Chinese[2];
	uint8_t j=0;
	while(*Str!='\0'){
		for(uint8_t i=0;i<2;i++){
			Chinese[i]=*Str;
			Str++;
		}
		for(uint8_t i=0;strcmp(arr_chinese8x16[i].top,"?")!=0;i++){
			if(strcmp(arr_chinese8x16[i].top,Chinese)==0){
			temp=i;
			break;
			}
			temp=i+1;
		}
		MYOLEDPLUS_ShowImage(x+16*j,y,16,16,arr_chinese8x16[temp].ARR);
		j++;
	}
}
