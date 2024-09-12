#include"lcd1602.h"
sbit LCD_RS=P2^6;
sbit LCD_RW=P2^5;
sbit LCD_RE=P2^7;
#define LCD_DATE P0
//延时函数
void delay(unsigned int count){
	unsigned char i,j;
	i=2;
	j=199;
	while(count--){
	do
	{
		while(--j);
	}while(--i);
		
	}
}
//命令函数
void LCDCMD(unsigned char num){
	LCD_RS=0;
	LCD_RW=0;
	LCD_RE=0;
	P0=num;
	LCD_RE=1;;
	delay(3);
	LCD_RE=0;
	delay(3);
}
//初始化
void LCD_Init(){
	LCDCMD(0x38);//数据总线8位，显示2行，5*7点阵/字符
	LCDCMD(0x0C);//显示功能开，无光标，光标闪烁
	LCDCMD(0x06);//写入新数据后光标右移，显示屏不移
	LCDCMD(0x01);//清屏
}
//数据写入
void LCD_WRITE_CHAR(unsigned char date){
	LCD_RS=1;
	LCD_RW=0;
	LCD_DATE=date;
	delay(3);
	LCD_RE=1;
	delay(3);
	LCD_RE=0;
}
int pow(int x,int y){
	int result=1;
	int i=0;
	for(i;i<y;i++){
		result=result*x;
	}
	return result;
}
//设置位置
void LCD_SET(unsigned char line,unsigned char column){
	if(line==1){
	LCDCMD(0x80|(column-1));
	}
	if(line==2){
	LCDCMD(0x80|(column-1+0x40));
	}
}
//显示数据
void LCD_SHOWSTRING(unsigned char line,unsigned char column,char* str){
	
	unsigned char location;
	if(line>1||column>15)
		return;
	if(line<1){
	while(*str!='\0'){
		if(location<16-column+1){
		LCDCMD(0x80+location+column-1);
		}
		else{
		LCDCMD(0x80+0x40+location+column-16-1);
		}
		LCD_WRITE_CHAR(*str);
		str++;
		location++;
	}
	}
	else{
	while(*str!='\0'){
		if(location<16-column+1){
		LCDCMD(0x80+0x40+location+column-1);
		}
		else{
		LCDCMD(0x80+location+column-16-1);
		}
		LCD_WRITE_CHAR(*str);
		str++;
		location++;
	}
	}
}
//数字长度
int length(int num){
	int length=0;
	while(num>0){
	num=num/10;
		length++;
	}
	return length;
}
//显示数字
void LCD_SHOWNUM(unsigned char line,unsigned char column,unsigned int num){
	unsigned char len=length(num);
	unsigned int i=0;
	unsigned char j=1;
	LCD_SET(line,column);
	if(line==1){
	for(i=len;i>0;i--){
		if(i>16-column){
	LCD_WRITE_CHAR(num/pow(10,i-1)%10+'0');
		}
		else{
		LCD_SET(2,j++);
		LCD_WRITE_CHAR(num/pow(10,i-1)%10+'0');
		}
	}
}
	else{
		j=1;
		for(i=len;i>0;i--){
		if(i>16-column){
	LCD_WRITE_CHAR(num/pow(10,i-1)%10+'0');
		}
		else{
		LCD_SET(1,j++);
		LCD_WRITE_CHAR(num/pow(10,i-1)%10+'0');
		}
	}
	}
}


//显示有符号数字
void LCD_SHOWSIGNEDNNUM(unsigned char line,unsigned char column,int num){
		unsigned int i=0;
		unsigned int len=0;
		unsigned int num1=0;
		LCD_SET(line,column);
		if(num>0){
		LCD_WRITE_CHAR('+');
			num1=num;
			len=length(num1);
		}
		else{
		LCD_WRITE_CHAR('-');
			num1=-num;
			len=length(num1);
		}
		for(i=len;i>0;i--){
			LCD_WRITE_CHAR(num1/pow(10,i-1)%10+'0');
		}
}