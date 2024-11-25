#include "stm32f10x.h"                  // Device header
#include <string.h>
#include "MYOLEDPLUS.h"
CAN_InitTypeDef CAN_LoopTestInit;
CAN_FilterInitTypeDef CAN_LoopTestFilterInit;
CanRxMsg CAN_RxLoopTestInit;
uint8_t RxFlage;
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
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//NVIC����
	//����NVIC
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel=USB_LP_CAN1_RX0_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVIC_InitStructure);

	//���ж�
	CAN_ITConfig(CAN1,CAN_IT_FMP0,ENABLE);
	
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
	//����32λ�б�ģʽ
//	CAN_LoopTestFilterInit.CAN_FilterActivation=ENABLE;//����������
//	CAN_LoopTestFilterInit.CAN_FilterFIFOAssignment=CAN_Filter_FIFO0;//�����ķ��͵�FIFO0
//	uint32_t id1=(0x123<<21);
//	CAN_LoopTestFilterInit.CAN_FilterIdHigh=id1>>16;
//	CAN_LoopTestFilterInit.CAN_FilterIdLow=id1;
//	uint32_t id2=((0x0789ABCDu<<3)|0x2|0x4);
//	CAN_LoopTestFilterInit.CAN_FilterMaskIdHigh=id2>>16;
//	CAN_LoopTestFilterInit.CAN_FilterMaskIdLow=id2;
//	CAN_LoopTestFilterInit.CAN_FilterMode=CAN_FilterMode_IdList;//�б�ģʽ
//	CAN_LoopTestFilterInit.CAN_FilterNumber=0;//��ʼ����һ��������
//	CAN_LoopTestFilterInit.CAN_FilterScale=CAN_FilterScale_32bit;//��ʮ��λ������
//	CAN_FilterInit(&CAN_LoopTestFilterInit);
	//����32λ����ģʽ
	CAN_LoopTestFilterInit.CAN_FilterActivation=ENABLE;//����������
	CAN_LoopTestFilterInit.CAN_FilterFIFOAssignment=CAN_Filter_FIFO0;//�����ķ��͵�FIFO0
	uint32_t id1=(0x12345600u<<3)|0x4;
	CAN_LoopTestFilterInit.CAN_FilterIdHigh=id1>>16;
	CAN_LoopTestFilterInit.CAN_FilterIdLow=id1;
	uint32_t id2=(0x1F000000u<<3)|0x4;
	CAN_LoopTestFilterInit.CAN_FilterMaskIdHigh=id2>>16;
	CAN_LoopTestFilterInit.CAN_FilterMaskIdLow=id2;
	CAN_LoopTestFilterInit.CAN_FilterMode=CAN_FilterMode_IdMask;//����ģʽ
	CAN_LoopTestFilterInit.CAN_FilterNumber=0;//��ʼ����һ��������
	CAN_LoopTestFilterInit.CAN_FilterScale=CAN_FilterScale_32bit;//��ʮ��λ������
	CAN_FilterInit(&CAN_LoopTestFilterInit);
	//�����������������б�������������
	/*
	CAN_LoopTestFilterInit.CAN_FilterIdHigh=0;
	CAN_LoopTestFilterInit.CAN_FilterIdLow=0;
	CAN_LoopTestFilterInit.CAN_FilterMaskIdHigh=0;
	CAN_LoopTestFilterInit.CAN_FilterMaskIdLow=0;
	CAN_LoopTestFilterInit.CAN_FilterMode=CAN_FilterMode_IdMask;//����ģʽ
	CAN_LoopTestFilterInit.CAN_FilterNumber=0;//��ʼ����һ��������
	CAN_LoopTestFilterInit.CAN_FilterScale=CAN_FilterScale_32bit;//��ʮ��λ������
	*/
}

void CANLoopTest_Send(CanTxMsg* CAN_LoopTest){
	uint8_t Num=CAN_Transmit(CAN1,CAN_LoopTest);
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

void CANLoopTest_Read(CanRxMsg* CAN_LoopTestInit){
	
}

void USB_LP_CAN1_RX0_IRQHandler(void){
	if(CAN_GetFlagStatus(CAN1,CAN_FLAG_FMP0)==SET){
		CAN_Receive(CAN1,CAN_FIFO0,&CAN_RxLoopTestInit);
		RxFlage=1;
	}
}
