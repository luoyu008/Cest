#include "main.h"
TIM_HandleTypeDef TIM_AdvancedCODTCtrlInit;
TIM_OC_InitTypeDef TIM_OC_AdvancedCODTCtrlInit;
TIM_BreakDeadTimeConfigTypeDef TIM_ACODTCtrlInit;
void AdvancedTimCODTCtrl_Init(void){
	//配置为1khz
	TIM_AdvancedCODTCtrlInit.Instance=TIM1;
	TIM_AdvancedCODTCtrlInit.Init.CounterMode=TIM_COUNTERMODE_UP;
	TIM_AdvancedCODTCtrlInit.Init.Period=100-1;
	TIM_AdvancedCODTCtrlInit.Init.Prescaler=720-1;
	TIM_AdvancedCODTCtrlInit.Init.ClockDivision=TIM_CLOCKDIVISION_DIV4;//四分频
	HAL_TIM_PWM_Init(&TIM_AdvancedCODTCtrlInit);
	//配置输出通道和互补输出通道
	TIM_OC_AdvancedCODTCtrlInit.OCIdleState=TIM_OCIDLESTATE_RESET;//空闲时输出低电平
	TIM_OC_AdvancedCODTCtrlInit.OCMode=TIM_OCMODE_PWM1;
	TIM_OC_AdvancedCODTCtrlInit.OCNIdleState=TIM_OCNIDLESTATE_RESET;//空闲状态输出低电平
	TIM_OC_AdvancedCODTCtrlInit.OCNPolarity=TIM_OCNPOLARITY_HIGH;//极性不反转 高电平有效
	TIM_OC_AdvancedCODTCtrlInit.OCPolarity=TIM_OCPOLARITY_HIGH;//极性不反转 高电平有效
	TIM_OC_AdvancedCODTCtrlInit.Pulse=50;//占空比50%
	HAL_TIM_PWM_ConfigChannel(&TIM_AdvancedCODTCtrlInit,&TIM_OC_AdvancedCODTCtrlInit,TIM_CHANNEL_1);
	
	TIM_ACODTCtrlInit.AutomaticOutput=TIM_AUTOMATICOUTPUT_ENABLE;//自动输出使能 刹车结束之后自动恢复输出
//	TIM_ACODTCtrlInit.BreakFilter=;7系列才可使用
	TIM_ACODTCtrlInit.BreakPolarity=TIM_BREAKPOLARITY_HIGH;//刹车输入高电平有效
	TIM_ACODTCtrlInit.BreakState=TIM_BREAK_ENABLE;//使能刹车输入
	TIM_ACODTCtrlInit.DeadTime=100;//DTG设置 死区时间5.56us
	TIM_ACODTCtrlInit.LockLevel=TIM_LOCKLEVEL_OFF;//锁定关闭
	TIM_ACODTCtrlInit.OffStateIDLEMode=TIM_OSSI_DISABLE;//定时器关闭时禁止输出
	TIM_ACODTCtrlInit.OffStateRunMode=TIM_OSSR_DISABLE;//定时器关闭时禁止输出
	HAL_TIMEx_ConfigBreakDeadTime(&TIM_AdvancedCODTCtrlInit,&TIM_ACODTCtrlInit);
	//使能输出和互补输出
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
