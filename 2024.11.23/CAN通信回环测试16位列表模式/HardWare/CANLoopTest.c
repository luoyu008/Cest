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
	//����16λ�б�ģʽ
//	CAN_LoopTestFilterInit.CAN_FilterActivation=ENABLE;//����������
//	CAN_LoopTestFilterInit.CAN_FilterFIFOAssignment=CAN_Filter_FIFO0;//�����ķ��͵�FIFO0
//	CAN_LoopTestFilterInit.CAN_FilterIdHigh=0x555<<5;
//	CAN_LoopTestFilterInit.CAN_FilterIdLow=(0x666<<5)|0x10;
//	CAN_LoopTestFilterInit.CAN_FilterMaskIdHigh=(0x688<<5)|0X10;
//	CAN_LoopTestFilterInit.CAN_FilterMaskIdLow=0x000<<5;
//	CAN_LoopTestFilterInit.CAN_FilterMode=CAN_FilterMode_IdList;//�б�ģʽ
//	CAN_LoopTestFilterInit.CAN_FilterNumber=0;//��ʼ����һ��������
//	CAN_LoopTestFilterInit.CAN_FilterScale=CAN_FilterScale_16bit;//ʮ��λ������
//	CAN_FilterInit(&CAN_LoopTestFilterInit);
	//����16λ����ģʽ
	CAN_LoopTestFilterInit.CAN_FilterActivation=ENABLE;//����������
	CAN_LoopTestFilterInit.CAN_FilterFIFOAssignment=CAN_Filter_FIFO0;//�����ķ��͵�FIFO0
	CAN_LoopTestFilterInit.CAN_FilterIdHigh=0x200<<5;
	CAN_LoopTestFilterInit.CAN_FilterMaskIdHigh=((0x700<<5))|0x8;
	CAN_LoopTestFilterInit.CAN_FilterIdLow=(0x320<<5);
	CAN_LoopTestFilterInit.CAN_FilterMaskIdLow=((0x7F0<<5))|0x8;
	CAN_LoopTestFilterInit.CAN_FilterMode=CAN_FilterMode_IdMask;//����ģʽ
	CAN_LoopTestFilterInit.CAN_FilterNumber=0;//��ʼ����һ��������
	CAN_LoopTestFilterInit.CAN_FilterScale=CAN_FilterScale_16bit;//ʮ��λ������
	CAN_FilterInit(&CAN_LoopTestFilterInit);
}

void CANLoopTest_NormalMode(void){
	CAN_OperatingModeRequest(CAN1,CAN_ModeStatus_Success);
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

uint8_t Receive_Flag(void){
	if(CAN_MessagePending(CAN1,CAN_FIFO0)>0){
		return 1;
	}
	return 0;
}

void CANLoopTest_Read(CanRxMsg* CAN_LoopTestInit){
	CAN_Receive(CAN1,CAN_FIFO0,CAN_LoopTestInit);
}
