#include "main.h"
TIM_HandleTypeDef TIM_IC_HandInit;
TIM_IC_InitTypeDef TIM_IC_Init;
uint16_t count2;
void ICmeasure_Init(void){
	TIM_IC_HandInit.Instance=TIM2;
	TIM_IC_HandInit.Init.CounterMode=TIM_COUNTERMODE_UP;
	TIM_IC_HandInit.Init.Period=65536-1;
	TIM_IC_HandInit.Init.Prescaler=72-1;
	HAL_TIM_IC_Init(&TIM_IC_HandInit);
	
	TIM_IC_Init.ICFilter=0;
	TIM_IC_Init.ICPolarity=TIM_ICPOLARITY_RISING;
	TIM_IC_Init.ICPrescaler=TIM_ICPSC_DIV1;
	TIM_IC_Init.ICSelection=TIM_ICSELECTION_INDIRECTTI;
	HAL_TIM_IC_ConfigChannel(&TIM_IC_HandInit,&TIM_IC_Init,TIM_CHANNEL_2);
	
	HAL_TIM_IC_Start(&TIM_IC_HandInit,TIM_CHANNEL_2);
	
	__HAL_TIM_ENABLE_IT(&TIM_IC_HandInit,TIM_IT_UPDATE);
	HAL_TIM_IC_Start_IT(&TIM_IC_HandInit,TIM_CHANNEL_2);
	
}

//void HAL_TIM_IC_MspInit(TIM_HandleTypeDef *htim){
//	if(htim->Instance==TIM2){
//		__HAL_RCC_GPIOA_CLK_ENABLE();
//		__HAL_RCC_TIM2_CLK_ENABLE();
//		GPIO_InitTypeDef GPIO_Init;
//		GPIO_Init.Mode=GPIO_MODE_INPUT;
//		GPIO_Init.Pin=GPIO_PIN_1;
//		GPIO_Init.Pull=GPIO_PULLDOWN;
//		GPIO_Init.Speed=GPIO_SPEED_FREQ_HIGH;
//		HAL_GPIO_Init(GPIOA,&GPIO_Init);
//		
//		HAL_NVIC_SetPriority(TIM2_IRQn,0,0);
//		HAL_NVIC_EnableIRQ(TIM2_IRQn);
//	}
//}

//uint16_t g_state;
//uint16_t g_count;
//void TIM2_IRQHandler(void){
//	HAL_TIM_IRQHandler(&TIM_IC_HandInit);
//}

//void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim){
//	if(htim->Instance==TIM2){
//		if((g_state&0x8000)!=1){//��ʾδ�������
//			if((g_state&0x4000)!=1){//��ʾ��һ��������δ����
//				g_state=0;
//				g_state|=0x40000;
//				__HAL_TIM_DISABLE(&TIM_IC_HandInit);//�ر�tim2ʱ��
//				__HAL_TIM_SET_COUNTER(&TIM_IC_HandInit,0);//�����ʱ������
//				TIM_RESET_CAPTUREPOLARITY(&TIM_IC_HandInit,TIM_CHANNEL_2);//�����ʱ��ͨ��������
//				TIM_SET_CAPTUREPOLARITY(&TIM_IC_HandInit,TIM_CHANNEL_2,TIM_ICPOLARITY_FALLING);//�����½��ز���
//				__HAL_TIM_ENABLE(&TIM_IC_HandInit);//��tim2ʱ��
//			}
//			else{//��ʾ��һ���������Ѿ�����
//				g_state|=0x8000;
//				g_count=HAL_TIM_ReadCapturedValue(&TIM_IC_HandInit,TIM_CHANNEL_2);//��ȡ��ǰ��������ֵ
//				TIM_RESET_CAPTUREPOLARITY(&TIM_IC_HandInit,TIM_CHANNEL_2);//�����ʱ��ͨ��������
//				TIM_SET_CAPTUREPOLARITY(&TIM_IC_HandInit,TIM_CHANNEL_2,TIM_ICPOLARITY_RISING);//���������ز���
//			}
//		}
//	}
//}

//void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
//	if(htim->Instance==TIM2){
//		if((g_state&0x8000)!=1){//δ�������ʱ
//			if((g_state&0x4000)==1){//���񵽸ߵ�ƽ
//				if(g_state&0x3fff==0x3fff){//�ߵ�ƽʱ��̫��
//				TIM_RESET_CAPTUREPOLARITY(&TIM_IC_HandInit,TIM_CHANNEL_2);//�����ʱ��ͨ��������
//				TIM_SET_CAPTUREPOLARITY(&TIM_IC_HandInit,TIM_CHANNEL_2,TIM_ICPOLARITY_RISING);//���������ز���
//				g_count=0xffff;
//				g_state|=0x8000;
//				}
//				else{
//					g_state++;
//				}
//			}
//		}
//	}
//}
