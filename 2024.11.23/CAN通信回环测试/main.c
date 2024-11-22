#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "MYOLEDPLUS.h"
#include "MYOLED_Data.h"
#include "KEY.h"
#include "CANLoopTest.h"
uint8_t a;
uint32_t ID=0x555;
uint32_t RID;
uint8_t length=4;
uint8_t Rlength;
uint8_t Data[8]={0,1,2,3};
int main()
{	
	KEY_Init(GPIOB,0);
	KEY_Init(GPIOB,1);
	MYOLEDPLUS_Init();	
	CANLoopTest_Init();
	MYOLEDPLUS_ShowString(0,0,"ID:",16);
	MYOLEDPLUS_ShowHexNum(25,0,ID,3,16);
	MYOLEDPLUS_ShowString(0,16,"RID:",16);
	MYOLEDPLUS_ShowString(0,32,"Length:",16);
	MYOLEDPLUS_ShowString(0,48,"Data:",16);
	MYOLEDPLUS_UpData();
	while(1){
		if(KEY_GET(GPIOB,0)){
		Data[0]++;
		Data[1]++;
		Data[2]++;
		Data[3]++;
		CANLoopTest_Send(ID,length,Data);
		}
		if(Receive_Flag()){
		CANLoopTest_Read(&RID,&Rlength,Data);
		}
		MYOLEDPLUS_ShowHexNum(30,16,RID,3,16);
		MYOLEDPLUS_ShowHexNum(55,32,Rlength,1,16);
		MYOLEDPLUS_ShowHexNum(38,48,Data[0],2,16);
		MYOLEDPLUS_ShowHexNum(56,48,Data[1],2,16);
		MYOLEDPLUS_ShowHexNum(74,48,Data[2],2,16);
		MYOLEDPLUS_ShowHexNum(92,48,Data[3],2,16);
		MYOLEDPLUS_UpData();
	}
}
