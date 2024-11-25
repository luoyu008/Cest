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

//CanTxMsg CAN_TxLoopTest[]={
//	{0x123,0x00000000,CAN_Id_Standard,CAN_RTR_Data,4,{0,1,2,3}},
//	{0x234,0x00000000,CAN_Id_Standard,CAN_RTR_Remote,0,{0,0,0,0}},
//	{0x345,0x00000000,CAN_Id_Standard,CAN_RTR_Data,4,{0,1,2,3}},
//	{0x456,0x00000000,CAN_Id_Standard,CAN_RTR_Remote,0,{0,0,0,0}},
//	{0x000,0x12345678,CAN_Id_Extended,CAN_RTR_Data,4,{0,1,2,3}},
//	{0x000,0x0789ABCD,CAN_Id_Extended,CAN_RTR_Remote,0,{0,0,0,0}},
////	{0x2FE,0x00000000,CAN_Id_Standard,CAN_RTR_Data,4,{0,1,2,3}},
////	{0x2FF,0x00000000,CAN_Id_Standard,CAN_RTR_Remote,0,{0,0,0,0}},
////	{0x310,0x00000000,CAN_Id_Standard,CAN_RTR_Data,4,{0,1,2,3}},
////	{0x31F,0x00000000,CAN_Id_Standard,CAN_RTR_Remote,0,{0,0,0,0}},
////	{0x320,0x00000000,CAN_Id_Standard,CAN_RTR_Data,4,{0,1,2,3}},
////	{0x32F,0x00000000,CAN_Id_Standard,CAN_RTR_Remote,0,{0,0,0,0}},
//};

CanTxMsg CAN_TxLoopTest[]={
	{0x000,0x12345600,CAN_Id_Extended,CAN_RTR_Data,4,{0,1,2,3}},
	{0x000,0x12345601,CAN_Id_Extended,CAN_RTR_Remote,0,{0,0,0,0}},
	{0x000,0x123456FE,CAN_Id_Extended,CAN_RTR_Data,4,{0,1,2,3}},
	{0x000,0x123456FF,CAN_Id_Extended,CAN_RTR_Remote,0,{0,0,0,0}},
	{0x000,0x0789AB00,CAN_Id_Extended,CAN_RTR_Data,0,{0,0,0,0}},
	{0x000,0x0789AB01,CAN_Id_Extended,CAN_RTR_Remote,4,{0,1,2,3}},
	{0x000,0x0789ABFE,CAN_Id_Extended,CAN_RTR_Data,0,{0,0,0,0}},
	{0x000,0x0789ABFF,CAN_Id_Extended,CAN_RTR_Remote,4,{0,1,2,3}},
};
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
		keynum++;
		MYOLEDPLUS_ShowHexNum(75,0,keynum,2,16);
		CANLoopTest_Send(&CAN_TxLoopTest[i]);
		i++;
		if(i>=sizeof(CAN_TxLoopTest)/sizeof(CanTxMsg)){
			i=0;
		}
		}
		if(RxFlage==1){
			RxFlage=0;
		if(CAN_RxLoopTestInit.IDE==CAN_Id_Standard){
			MYOLEDPLUS_ShowHexNum(30,16,CAN_RxLoopTestInit.StdId,8,16);
		}
		else if(CAN_RxLoopTestInit.IDE==CAN_Id_Extended){
			MYOLEDPLUS_ShowHexNum(30,16,CAN_RxLoopTestInit.ExtId,8,16);
		}
		MYOLEDPLUS_ShowHexNum(55,32,CAN_RxLoopTestInit.DLC,1,16);
		if(CAN_RxLoopTestInit.RTR==CAN_RTR_Data){
			MYOLEDPLUS_ShowString(25,0,"Data  ",16);
			MYOLEDPLUS_ShowHexNum(38,48,CAN_RxLoopTestInit.Data[0],2,16);
			MYOLEDPLUS_ShowHexNum(56,48,CAN_RxLoopTestInit.Data[1],2,16);
			MYOLEDPLUS_ShowHexNum(74,48,CAN_RxLoopTestInit.Data[2],2,16);
			MYOLEDPLUS_ShowHexNum(92,48,CAN_RxLoopTestInit.Data[3],2,16);

		}
		else if(CAN_RxLoopTestInit.RTR==CAN_RTR_Remote){
			MYOLEDPLUS_ShowString(25,0,"Remote",16);
			MYOLEDPLUS_ShowHexNum(38,48,0,2,16);
			MYOLEDPLUS_ShowHexNum(56,48,0,2,16);
			MYOLEDPLUS_ShowHexNum(74,48,0,2,16);
			MYOLEDPLUS_ShowHexNum(92,48,0,2,16);
		}
	}
		MYOLEDPLUS_UpData();
	}
}
