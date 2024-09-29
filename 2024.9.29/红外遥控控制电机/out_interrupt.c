#include "out_interrupt.h"
unsigned char state;//电平状态
unsigned int count;//计数器0计的数
unsigned char ARR[4];//解码之后的四个数存储
unsigned char date;//数组下标
unsigned char address;//地址码
unsigned char commend;//命令码
unsigned char dateflage;//得到数据的标志
unsigned char repeatflage;//连发的标志
//unsigned char i,j;//i为四个数的循环，j为八位字节循环
void out_Init()
{
	IT0=1;
	IE0=0;
	EX0=1;
	EA=1;
	PX0=1;
}
unsigned char out0_getdateflage(){
	if(dateflage){
		dateflage=0;
		return 1;
	}
	return 0;
}
unsigned char out0_getrepeatflage(){
	if(repeatflage)
	{
		repeatflage=0;
		return 1;
	}
	return 0;
}
unsigned char out0_returnadd()//返回地址码
{
	return address;
}
unsigned char out0_returncom()//返回命令码
{
	return commend;
}
void out0() interrupt 0
{
	if(state==0){//空闲状态
		time0_set(0);//设置计数器0从0开始计数
		time0_con(1);//设置计数器0开始记数
		state=1;//转化为状态1 即收到红外信号状态
	}
	else if(state==1){
		count=time0_return();
		time0_set(0);
		if(count>=12442-500&&count<=12442+500){//若count在9ms+4.5ms计数范围之内转化为状态2
			//即开始解码状态
			state=2;
		}
		else if(count>=10368-500&&count<=10368+500){//若在9ms+2.25ms计数范围之内转化为状态0
			//即重新接受信号状态	
			repeatflage=1;
			time0_con(0);//关闭计数器
			state=0;
		}else
		{
			state=1;
		}
		}
	else if(state==2){
//		for(i=0;i<4;i++){
//			for(j=0;j<8;j++){
				count=time0_return();
				time0_set(0);
				if(count>=2074-500&&count<=2074+500){//收到数据1
//					ARR[i]|=(0x01<<j);
				ARR[date/8]|=(0x01<<(date%8));
					date++;
				}
				else if(count>=1032-500&&count<=1032+500){//收到数据0
//					ARR[i]&=~(0x01<<j);
				ARR[date/8]&=~(0x01<<(date%8));
					date++;
				}
				else{//既没有收到数据1也没有收到数据0 
				date=0;
				state=1;
				}
//			}
//		}
				if(date>=32){
		date=0;
		if((ARR[0]==~ARR[1])&&(ARR[2]==~ARR[3])){	P2=0;
			//判断数据是否正确
		address=ARR[0];
		commend=ARR[2];
			dateflage=1;
		}
		time0_con(0);
		state=0;
	}
	}
}