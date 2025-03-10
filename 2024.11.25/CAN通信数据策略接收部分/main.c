#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "MYOLEDPLUS.h"
#include "MYOLED_Data.h"
#include "KEY.h"
#include "CANLoopTest.h"
#include "Time.h"
uint8_t keynum;
//CanTxMsg CAN_TxLoopTest[]={
//	{0x555,0x00000000,CAN_Id_Standard,CAN_RTR_Data,4,{0,1,2,3}},
//	{0x666,0x00000000,CAN_Id_Standard,CAN_RTR_Remote,0,{0,0,0,0}},
//	{0x000,0x12345678,CAN_Id_Extended,CAN_RTR_Data,4,{0,1,2,3}},
//	{0x000,0x23456789,CAN_Id_Extended,CAN_RTR_Remote,0,{0,0,0,0}},
//};

CanTxMsg CAN_TxLoopTest[]={
	{0x123,0x00000000,CAN_Id_Standard,CAN_RTR_Data,4,{0,1,2,3}},
	{0x234,0x00000000,CAN_Id_Standard,CAN_RTR_Remote,0,{0,0,0,0}},
	{0x345,0x00000000,CAN_Id_Standard,CAN_RTR_Data,4,{0,1,2,3}},
	{0x456,0x00000000,CAN_Id_Standard,CAN_RTR_Remote,0,{0,0,0,0}},
	{0x000,0x12345678,CAN_Id_Extended,CAN_RTR_Data,4,{0,1,2,3}},
	{0x000,0x0789ABCD,CAN_Id_Extended,CAN_RTR_Remote,0,{0,0,0,0}},
	{0x2FE,0x00000000,CAN_Id_Standard,CAN_RTR_Data,4,{0,1,2,3}},
	{0x2FF,0x00000000,CAN_Id_Standard,CAN_RTR_Remote,0,{0,0,0,0}},
	{0x310,0x00000000,CAN_Id_Standard,CAN_RTR_Data,4,{0,1,2,3}},
	{0x31F,0x00000000,CAN_Id_Standard,CAN_RTR_Remote,0,{0,0,0,0}},
	{0x320,0x00000000,CAN_Id_Standard,CAN_RTR_Data,4,{0,1,2,3}},
	{0x32F,0x00000000,CAN_Id_Standard,CAN_RTR_Remote,0,{0,0,0,0}},
};

//CanTxMsg CAN_TxLoopTest[]={
//	{0x000,0x12345600,CAN_Id_Extended,CAN_RTR_Data,4,{0,1,2,3}},
//	{0x000,0x12345601,CAN_Id_Extended,CAN_RTR_Remote,0,{0,0,0,0}},
//	{0x000,0x123456FE,CAN_Id_Extended,CAN_RTR_Data,4,{0,1,2,3}},
//	{0x000,0x123456FF,CAN_Id_Extended,CAN_RTR_Remote,0,{0,0,0,0}},
//	{0x000,0x0789AB00,CAN_Id_Extended,CAN_RTR_Data,0,{0,0,0,0}},
//	{0x000,0x0789AB01,CAN_Id_Extended,CAN_RTR_Remote,4,{0,1,2,3}},
//	{0x000,0x0789ABFE,CAN_Id_Extended,CAN_RTR_Data,0,{0,0,0,0}},
//	{0x000,0x0789ABFF,CAN_Id_Extended,CAN_RTR_Remote,4,{0,1,2,3}},
//};
uint8_t i,j;
int main()
{	
	KEY_Init(GPIOB,0);
	KEY_Init(GPIOB,1);
	MYOLEDPLUS_Init();	
	CANLoopTest_Init();
	MYOLEDPLUS_ShowString(0,0,"Rx:",16);
	MYOLEDPLUS_ShowString(0,16,"ID:",16);
	MYOLEDPLUS_ShowString(0,32,"KID:",16);
	MYOLEDPLUS_UpData();
	while(1){
		/*
		按键发送
		*/
		if(KEY_GET(GPIOB,0)){
		MYOLEDPLUS_ShowHexNum(75,0,i,2,16);
		CANLoopTest_Send(&CAN_TxLoopTest[i]);
		i++;
		if(i>=sizeof(CAN_TxLoopTest)/sizeof(CanTxMsg)){
			i=0;
		}
		}
		/*
		接受报文
		*/
		RxFlage=Receive_Flag();
		if(RxFlage==1){
			RxFlage=0;
			CANLoopTest_Read();
			if(CAN_RxLoopTestInit.IDE==CAN_Id_Standard){
			MYOLEDPLUS_ShowHexNum(30,16,CAN_RxLoopTestInit.StdId,8,16);
			}
		else if(CAN_RxLoopTestInit.IDE==CAN_Id_Extended){
			MYOLEDPLUS_ShowHexNum(30,16,CAN_RxLoopTestInit.ExtId,8,16);
			}
			/*
			接收请求回复
			*/
			if(CAN_RxLoopTestInit.StdId==0x011){
				MYOLEDPLUS_ShowHexNum(40,32,CAN_RxLoopTestInit.StdId,8,16);
			}
			else if(CAN_RxLoopTestInit.StdId==0x022){
				MYOLEDPLUS_ShowHexNum(40,32,CAN_RxLoopTestInit.StdId,8,16);
			}
			else if(CAN_RxLoopTestInit.StdId==0x033){
				MYOLEDPLUS_ShowHexNum(40,32,CAN_RxLoopTestInit.StdId,8,16);
			}
			
		}
		MYOLEDPLUS_UpData();
	}
}
