#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "MYOLEDPLUS.h"
#include "MYOLED_Data.h"
#include "KEY.h"
#include "CANLoopTest.h"
uint8_t keynum;
//CanTxMsg CAN_TxLoopTest[]={
//	{0x555,0x00000000,CAN_Id_Standard,CAN_RTR_Data,4,{0,1,2,3}},
//	{0x666,0x00000000,CAN_Id_Standard,CAN_RTR_Remote,0,{0,0,0,0}},
//	{0x000,0x12345678,CAN_Id_Extended,CAN_RTR_Data,4,{0,1,2,3}},
//	{0x000,0x23456789,CAN_Id_Extended,CAN_RTR_Remote,0,{0,0,0,0}},
//};

CanTxMsg CAN_TxLoopTest[]={
	{0x100,0x00000000,CAN_Id_Standard,CAN_RTR_Data,4,{0,1,2,3}},
	{0x101,0x00000000,CAN_Id_Standard,CAN_RTR_Remote,0,{0,0,0,0}},
	{0x1FE,0x00000000,CAN_Id_Standard,CAN_RTR_Data,4,{0,1,2,3}},
	{0x1FF,0x00000000,CAN_Id_Standard,CAN_RTR_Remote,0,{0,0,0,0}},
	{0x200,0x00000000,CAN_Id_Standard,CAN_RTR_Data,4,{0,1,2,3}},
	{0x201,0x00000000,CAN_Id_Standard,CAN_RTR_Remote,0,{0,0,0,0}},
	{0x2FE,0x00000000,CAN_Id_Standard,CAN_RTR_Data,4,{0,1,2,3}},
	{0x2FF,0x00000000,CAN_Id_Standard,CAN_RTR_Remote,0,{0,0,0,0}},
	{0x310,0x00000000,CAN_Id_Standard,CAN_RTR_Data,4,{0,1,2,3}},
	{0x31F,0x00000000,CAN_Id_Standard,CAN_RTR_Remote,0,{0,0,0,0}},
	{0x320,0x00000000,CAN_Id_Standard,CAN_RTR_Data,4,{0,1,2,3}},
	{0x32F,0x00000000,CAN_Id_Standard,CAN_RTR_Remote,0,{0,0,0,0}},
};

CanRxMsg CAN_RxLoopTest;
uint8_t i;
int main()
{	
	KEY_Init(GPIOB,0);
	KEY_Init(GPIOB,1);
	MYOLEDPLUS_Init();	
	CANLoopTest_Init();
	MYOLEDPLUS_ShowString(0,0,"Rx:",16);
	MYOLEDPLUS_ShowString(0,16,"ID:",16);
	MYOLEDPLUS_ShowString(0,32,"Length:",16);
	MYOLEDPLUS_ShowString(0,48,"Data:",16);
	MYOLEDPLUS_UpData();
	while(1){
		if(KEY_GET(GPIOB,0)){
//		CAN_TxLoopTest.Data[0]++;
//		CAN_TxLoopTest.Data[1]++;
//		CAN_TxLoopTest.Data[2]++;
//		CAN_TxLoopTest.Data[3]++;
		keynum++;
		MYOLEDPLUS_ShowHexNum(75,0,keynum,2,16);
		CANLoopTest_Send(&CAN_TxLoopTest[i]);
		i++;
		if(i>=sizeof(CAN_TxLoopTest)/sizeof(CanTxMsg)){
			i=0;
		}
		}
		if(Receive_Flag()){
		CANLoopTest_Read(&CAN_RxLoopTest);
		}
		if(CAN_RxLoopTest.IDE==CAN_Id_Standard){
			MYOLEDPLUS_ShowHexNum(30,16,CAN_RxLoopTest.StdId,8,16);
		}
		else if(CAN_RxLoopTest.IDE==CAN_Id_Extended){
			MYOLEDPLUS_ShowHexNum(30,16,CAN_RxLoopTest.ExtId,8,16);
		}
		MYOLEDPLUS_ShowHexNum(55,32,CAN_RxLoopTest.DLC,1,16);
		if(CAN_RxLoopTest.RTR==CAN_RTR_Data){
			MYOLEDPLUS_ShowString(25,0,"Data  ",16);
			MYOLEDPLUS_ShowHexNum(38,48,CAN_RxLoopTest.Data[0],2,16);
			MYOLEDPLUS_ShowHexNum(56,48,CAN_RxLoopTest.Data[1],2,16);
			MYOLEDPLUS_ShowHexNum(74,48,CAN_RxLoopTest.Data[2],2,16);
			MYOLEDPLUS_ShowHexNum(92,48,CAN_RxLoopTest.Data[3],2,16);

		}
		else if(CAN_RxLoopTest.RTR==CAN_RTR_Remote){
			MYOLEDPLUS_ShowString(25,0,"Remote",16);
			MYOLEDPLUS_ShowHexNum(38,48,0,2,16);
			MYOLEDPLUS_ShowHexNum(56,48,0,2,16);
			MYOLEDPLUS_ShowHexNum(74,48,0,2,16);
			MYOLEDPLUS_ShowHexNum(92,48,0,2,16);
		}
		MYOLEDPLUS_UpData();
	}
}
