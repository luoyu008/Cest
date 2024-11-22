#include "stm32f10x.h"                  // Device header
#include <string.h>
#include "MYOLEDPLUS.h"
CAN_InitTypeDef CAN_LoopTestInit;
CAN_FilterInitTypeDef CAN_LoopTestFilterInit;
void CANLoopTest_Init(void){
	//打开can1,gpioa时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	//初始化	GPIO口
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_12;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_11;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	
	//配置波特率为125k  由于是高速CAN 波特率要在125k~1M取值
	CAN_LoopTestInit.CAN_ABOM=DISABLE;//关闭自动离线管理
	CAN_LoopTestInit.CAN_AWUM=DISABLE;//关闭自动唤醒模式 使用软件唤醒
	CAN_LoopTestInit.CAN_BS1=CAN_BS1_2tq;
	CAN_LoopTestInit.CAN_BS2=CAN_BS2_3tq;
	CAN_LoopTestInit.CAN_Mode=CAN_Mode_LoopBack;//环回测试模式
	CAN_LoopTestInit.CAN_NART=DISABLE;//启动自动重传模式
	CAN_LoopTestInit.CAN_Prescaler=48;//APB1总线时钟48分频
	CAN_LoopTestInit.CAN_RFLM=DISABLE;//关闭FIFO锁 收件箱满之后的报文替换最后一个
	CAN_LoopTestInit.CAN_SJW=CAN_SJW_2tq;//延迟的最大位数为2
	CAN_LoopTestInit.CAN_TTCM=DISABLE;//关闭时间戳产生功能
	CAN_LoopTestInit.CAN_TXFP=DISABLE;//发送的优先级由报文的标识符决定即ID号 ID号小的先发送
	CAN_Init(CAN1,&CAN_LoopTestInit);
	//配置32位屏蔽模式
	CAN_LoopTestFilterInit.CAN_FilterActivation=ENABLE;//启动过滤器
	CAN_LoopTestFilterInit.CAN_FilterFIFOAssignment=CAN_Filter_FIFO0;//将报文发送到FIFO0
	CAN_LoopTestFilterInit.CAN_FilterIdHigh=0;
	CAN_LoopTestFilterInit.CAN_FilterIdLow=0;
	CAN_LoopTestFilterInit.CAN_FilterMaskIdHigh=0;
	CAN_LoopTestFilterInit.CAN_FilterMaskIdLow=0;
	CAN_LoopTestFilterInit.CAN_FilterMode=CAN_FilterMode_IdMask;//屏蔽模式
	CAN_LoopTestFilterInit.CAN_FilterNumber=0;//初始化第一个过滤器
	CAN_LoopTestFilterInit.CAN_FilterScale=CAN_FilterScale_32bit;//三十二位过滤器
	CAN_FilterInit(&CAN_LoopTestFilterInit);
	
}

void CANLoopTest_NormalMode(void){
	CAN_OperatingModeRequest(CAN1,CAN_ModeStatus_Success);
}

void CANLoopTest_Send(uint32_t ID,uint8_t length,uint8_t* Data){
	CanTxMsg CAN_LoopTest;
	memcpy(CAN_LoopTest.Data, Data, sizeof(CAN_LoopTest.Data)); // 复制8字节数据 
//	CAN_LoopTest.Data=Data[0];//数组的起始地址
	CAN_LoopTest.DLC=length;//传输的数据帧的长度为4
	CAN_LoopTest.ExtId=0;//扩展ID为0
	CAN_LoopTest.IDE=CAN_Id_Standard;//标准ID
	CAN_LoopTest.RTR=CAN_RTR_Data;//传输的是数据帧
	CAN_LoopTest.StdId=ID;//标识ID为0x555
	uint8_t Num=CAN_Transmit(CAN1,&CAN_LoopTest);
	uint32_t TimeOut=0;
	while(CAN_TransmitStatus(CAN1,Num)!=CAN_TxStatus_Ok){
		TimeOut++;
		if(TimeOut>100000){
			MYOLEDPLUS_ShowHexNum(80,20,98,2,16);
			MYOLEDPLUS_UpData();
			break;
		}
	}
}

uint8_t Receive_Flag(void){
	if(CAN_MessagePending(CAN1,CAN_FIFO0)>0){
		return 1;
	}
	return 0;
}

void CANLoopTest_Read(uint32_t* ID,uint8_t* length,uint8_t* Data){
	CanRxMsg CAN_LoopTestInit;
	CAN_Receive(CAN1,CAN_FIFO0,&CAN_LoopTestInit);
	
	if(CAN_LoopTestInit.IDE==CAN_Id_Standard){//接收到的是标准ID
		*ID=CAN_LoopTestInit.StdId;
	}
	else
	{
		*ID=CAN_LoopTestInit.ExtId;
	}
	if(CAN_LoopTestInit.RTR==CAN_RTR_Data){//接收到的是数据帧
		*length=CAN_LoopTestInit.DLC;
		for(uint8_t i=0;i<8;i++){
			Data[i]=CAN_LoopTestInit.Data[i];
		}
	}
	else{
		//遥控帧
	}
}
