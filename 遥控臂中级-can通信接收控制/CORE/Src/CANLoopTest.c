#include "main.h"
CAN_HandleTypeDef CAN_LoopTestInit;
CAN_FilterTypeDef CAN_LoopTestFilterInit;
void CANLoopTest_Init(void){
	//����125k������
	CAN_LoopTestInit.Instance=CAN1;
	CAN_LoopTestInit.Init.AutoBusOff=DISABLE;//�����Զ����߹���
	CAN_LoopTestInit.Init.AutoRetransmission=DISABLE;//�����Զ��ش�ģʽ
	CAN_LoopTestInit.Init.AutoWakeUp=DISABLE;//�����Զ�����ģʽ ��ʹ���������
	CAN_LoopTestInit.Init.Mode=CAN_MODE_NORMAL;//�ػ�����ģʽ
	CAN_LoopTestInit.Init.Prescaler=48;
	CAN_LoopTestInit.Init.ReceiveFifoLocked=DISABLE;//����FIFO����ģʽ
	CAN_LoopTestInit.Init.SyncJumpWidth=CAN_SJW_2TQ;//�Զ�����2λʱ
	CAN_LoopTestInit.Init.TimeSeg1=CAN_BS1_2TQ;
	CAN_LoopTestInit.Init.TimeSeg2=CAN_BS2_3TQ;
	CAN_LoopTestInit.Init.TimeTriggeredMode=DISABLE;//�ر�ʱ��ͨ��ģʽ
	CAN_LoopTestInit.Init.TransmitFifoPriority=DISABLE;//����FIFO�������ȼ�
	HAL_CAN_Init(&CAN_LoopTestInit);
	//32λ����ģʽ ��ͨ�����Ա���
	CAN_LoopTestFilterInit.FilterActivation=CAN_FILTER_ENABLE;//����������
	CAN_LoopTestFilterInit.FilterBank=0;//��ʼ����һ��������
	CAN_LoopTestFilterInit.FilterFIFOAssignment=CAN_FILTER_FIFO0;//��������Ϣ�ŵ�FIFO0��
	CAN_LoopTestFilterInit.FilterIdHigh=0;
	CAN_LoopTestFilterInit.FilterIdLow=0;
	CAN_LoopTestFilterInit.FilterMaskIdHigh=0;
	CAN_LoopTestFilterInit.FilterMaskIdLow=0;
	CAN_LoopTestFilterInit.FilterMode=CAN_FILTERMODE_IDMASK;
	CAN_LoopTestFilterInit.FilterScale=CAN_FILTERSCALE_32BIT;
//	CAN_LoopTestFilterInit.FilterMode=CAN_FILTERMODE_IDLIST;
//	CAN_LoopTestFilterInit.FilterScale=CAN_FILTERSCALE_16BIT;
	CAN_LoopTestFilterInit.SlaveStartFilterBank=14;
	HAL_CAN_ConfigFilter(&CAN_LoopTestInit,&CAN_LoopTestFilterInit);
	
	HAL_CAN_Start(&CAN_LoopTestInit);
}


void HAL_CAN_MspInit(CAN_HandleTypeDef *hcan){
	if(hcan->Instance==CAN1){
		__HAL_RCC_GPIOA_CLK_ENABLE();
		__HAL_RCC_CAN1_CLK_ENABLE();
		
		GPIO_InitTypeDef GPIO_Init;
		GPIO_Init.Mode=GPIO_MODE_AF_PP;
		GPIO_Init.Pin=GPIO_PIN_12;
		GPIO_Init.Pull=GPIO_NOPULL;
		GPIO_Init.Speed=GPIO_SPEED_FREQ_HIGH;
		HAL_GPIO_Init(GPIOA,&GPIO_Init);
		
		GPIO_Init.Mode=GPIO_MODE_AF_INPUT;
		GPIO_Init.Pin=GPIO_PIN_11;
		GPIO_Init.Pull=GPIO_PULLUP;
		GPIO_Init.Speed=GPIO_SPEED_FREQ_HIGH;
		HAL_GPIO_Init(GPIOA,&GPIO_Init);
	}
}

