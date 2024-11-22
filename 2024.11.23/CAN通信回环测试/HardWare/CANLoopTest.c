#include "stm32f10x.h"                  // Device header
#include <string.h>
#include "MYOLEDPLUS.h"
CAN_InitTypeDef CAN_LoopTestInit;
CAN_FilterInitTypeDef CAN_LoopTestFilterInit;
void CANLoopTest_Init(void){
	//��can1,gpioaʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	//��ʼ��	GPIO��
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_12;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_11;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	
	//���ò�����Ϊ125k  �����Ǹ���CAN ������Ҫ��125k~1Mȡֵ
	CAN_LoopTestInit.CAN_ABOM=DISABLE;//�ر��Զ����߹���
	CAN_LoopTestInit.CAN_AWUM=DISABLE;//�ر��Զ�����ģʽ ʹ���������
	CAN_LoopTestInit.CAN_BS1=CAN_BS1_2tq;
	CAN_LoopTestInit.CAN_BS2=CAN_BS2_3tq;
	CAN_LoopTestInit.CAN_Mode=CAN_Mode_LoopBack;//���ز���ģʽ
	CAN_LoopTestInit.CAN_NART=DISABLE;//�����Զ��ش�ģʽ
	CAN_LoopTestInit.CAN_Prescaler=48;//APB1����ʱ��48��Ƶ
	CAN_LoopTestInit.CAN_RFLM=DISABLE;//�ر�FIFO�� �ռ�����֮��ı����滻���һ��
	CAN_LoopTestInit.CAN_SJW=CAN_SJW_2tq;//�ӳٵ����λ��Ϊ2
	CAN_LoopTestInit.CAN_TTCM=DISABLE;//�ر�ʱ�����������
	CAN_LoopTestInit.CAN_TXFP=DISABLE;//���͵����ȼ��ɱ��ĵı�ʶ��������ID�� ID��С���ȷ���
	CAN_Init(CAN1,&CAN_LoopTestInit);
	//����32λ����ģʽ
	CAN_LoopTestFilterInit.CAN_FilterActivation=ENABLE;//����������
	CAN_LoopTestFilterInit.CAN_FilterFIFOAssignment=CAN_Filter_FIFO0;//�����ķ��͵�FIFO0
	CAN_LoopTestFilterInit.CAN_FilterIdHigh=0;
	CAN_LoopTestFilterInit.CAN_FilterIdLow=0;
	CAN_LoopTestFilterInit.CAN_FilterMaskIdHigh=0;
	CAN_LoopTestFilterInit.CAN_FilterMaskIdLow=0;
	CAN_LoopTestFilterInit.CAN_FilterMode=CAN_FilterMode_IdMask;//����ģʽ
	CAN_LoopTestFilterInit.CAN_FilterNumber=0;//��ʼ����һ��������
	CAN_LoopTestFilterInit.CAN_FilterScale=CAN_FilterScale_32bit;//��ʮ��λ������
	CAN_FilterInit(&CAN_LoopTestFilterInit);
	
}

void CANLoopTest_NormalMode(void){
	CAN_OperatingModeRequest(CAN1,CAN_ModeStatus_Success);
}

void CANLoopTest_Send(uint32_t ID,uint8_t length,uint8_t* Data){
	CanTxMsg CAN_LoopTest;
	memcpy(CAN_LoopTest.Data, Data, sizeof(CAN_LoopTest.Data)); // ����8�ֽ����� 
//	CAN_LoopTest.Data=Data[0];//�������ʼ��ַ
	CAN_LoopTest.DLC=length;//���������֡�ĳ���Ϊ4
	CAN_LoopTest.ExtId=0;//��չIDΪ0
	CAN_LoopTest.IDE=CAN_Id_Standard;//��׼ID
	CAN_LoopTest.RTR=CAN_RTR_Data;//�����������֡
	CAN_LoopTest.StdId=ID;//��ʶIDΪ0x555
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
	
	if(CAN_LoopTestInit.IDE==CAN_Id_Standard){//���յ����Ǳ�׼ID
		*ID=CAN_LoopTestInit.StdId;
	}
	else
	{
		*ID=CAN_LoopTestInit.ExtId;
	}
	if(CAN_LoopTestInit.RTR==CAN_RTR_Data){//���յ���������֡
		*length=CAN_LoopTestInit.DLC;
		for(uint8_t i=0;i<8;i++){
			Data[i]=CAN_LoopTestInit.Data[i];
		}
	}
	else{
		//ң��֡
	}
}
