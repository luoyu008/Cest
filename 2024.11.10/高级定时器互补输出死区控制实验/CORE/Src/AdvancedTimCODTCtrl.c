#include "main.h"
TIM_HandleTypeDef TIM_AdvancedCODTCtrlInit;
TIM_OC_InitTypeDef TIM_OC_AdvancedCODTCtrlInit;
TIM_BreakDeadTimeConfigTypeDef TIM_ACODTCtrlInit;
void AdvancedTimCODTCtrl_Init(void){
	//����Ϊ1khz
	TIM_AdvancedCODTCtrlInit.Instance=TIM1;
	TIM_AdvancedCODTCtrlInit.Init.CounterMode=TIM_COUNTERMODE_UP;
	TIM_AdvancedCODTCtrlInit.Init.Period=100-1;
	TIM_AdvancedCODTCtrlInit.Init.Prescaler=720-1;
	TIM_AdvancedCODTCtrlInit.Init.ClockDivision=TIM_CLOCKDIVISION_DIV4;//�ķ�Ƶ
	HAL_TIM_PWM_Init(&TIM_AdvancedCODTCtrlInit);
	//�������ͨ���ͻ������ͨ��
	TIM_OC_AdvancedCODTCtrlInit.OCIdleState=TIM_OCIDLESTATE_RESET;//����ʱ����͵�ƽ
	TIM_OC_AdvancedCODTCtrlInit.OCMode=TIM_OCMODE_PWM1;
	TIM_OC_AdvancedCODTCtrlInit.OCNIdleState=TIM_OCNIDLESTATE_RESET;//����״̬����͵�ƽ
	TIM_OC_AdvancedCODTCtrlInit.OCNPolarity=TIM_OCNPOLARITY_HIGH;//���Բ���ת �ߵ�ƽ��Ч
	TIM_OC_AdvancedCODTCtrlInit.OCPolarity=TIM_OCPOLARITY_HIGH;//���Բ���ת �ߵ�ƽ��Ч
	TIM_OC_AdvancedCODTCtrlInit.Pulse=50;//ռ�ձ�50%
	HAL_TIM_PWM_ConfigChannel(&TIM_AdvancedCODTCtrlInit,&TIM_OC_AdvancedCODTCtrlInit,TIM_CHANNEL_1);
	
	TIM_ACODTCtrlInit.AutomaticOutput=TIM_AUTOMATICOUTPUT_ENABLE;//�Զ����ʹ�� ɲ������֮���Զ��ָ����
//	TIM_ACODTCtrlInit.BreakFilter=;7ϵ�вſ�ʹ��
	TIM_ACODTCtrlInit.BreakPolarity=TIM_BREAKPOLARITY_HIGH;//ɲ������ߵ�ƽ��Ч
	TIM_ACODTCtrlInit.BreakState=TIM_BREAK_ENABLE;//ʹ��ɲ������
	TIM_ACODTCtrlInit.DeadTime=100;//DTG���� ����ʱ��5.56us
	TIM_ACODTCtrlInit.LockLevel=TIM_LOCKLEVEL_OFF;//�����ر�
	TIM_ACODTCtrlInit.OffStateIDLEMode=TIM_OSSI_DISABLE;//��ʱ���ر�ʱ��ֹ���
	TIM_ACODTCtrlInit.OffStateRunMode=TIM_OSSR_DISABLE;//��ʱ���ر�ʱ��ֹ���
	HAL_TIMEx_ConfigBreakDeadTime(&TIM_AdvancedCODTCtrlInit,&TIM_ACODTCtrlInit);
	//ʹ������ͻ������
	HAL_TIM_PWM_Start(&TIM_AdvancedCODTCtrlInit,TIM_CHANNEL_1);
	HAL_TIMEx_PWMN_Start(&TIM_AdvancedCODTCtrlInit,TIM_CHANNEL_1);
}

void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim){
	if(htim->Instance==TIM1){
		__HAL_RCC_TIM1_CLK_ENABLE();
		__HAL_RCC_GPIOA_CLK_ENABLE();
		__HAL_RCC_GPIOB_CLK_ENABLE();
		
		GPIO_InitTypeDef GPIO_Init;
		GPIO_Init.Mode=GPIO_MODE_AF_PP;
		GPIO_Init.Pin=GPIO_PIN_8;
		GPIO_Init.Pull=GPIO_PULLUP;
		GPIO_Init.Speed=GPIO_SPEED_FREQ_HIGH;
		HAL_GPIO_Init(GPIOA,&GPIO_Init);
		GPIO_Init.Mode=GPIO_MODE_AF_PP;
		GPIO_Init.Pin=GPIO_PIN_13;
		GPIO_Init.Pull=GPIO_PULLUP;
		GPIO_Init.Speed=GPIO_SPEED_FREQ_HIGH;
		HAL_GPIO_Init(GPIOB,&GPIO_Init);
		GPIO_Init.Mode=GPIO_MODE_INPUT;
		GPIO_Init.Pin=GPIO_PIN_12;
		GPIO_Init.Pull=GPIO_PULLDOWN;
		GPIO_Init.Speed=GPIO_SPEED_FREQ_HIGH;
		HAL_GPIO_Init(GPIOB,&GPIO_Init);
	}
}
