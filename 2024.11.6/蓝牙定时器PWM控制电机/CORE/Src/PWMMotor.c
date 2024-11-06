#include "main.h"
#include "OLED.h"
TIM_HandleTypeDef TIM_HandInit={0};
TIM_OC_InitTypeDef TIM_OC_Init={0};
void PWM_Init(void){
	//����1khz 
	TIM_HandInit.Instance=TIM2;
	TIM_HandInit.Init.Period=100-1;
	TIM_HandInit.Init.Prescaler=720-1;
	TIM_HandInit.Init.CounterMode=TIM_COUNTERMODE_UP;
	if(HAL_TIM_PWM_Init(&TIM_HandInit)!=HAL_OK){
		OLED_ShowChar(0,0,'A',16);
		OLED_UpData();
	}
	
	TIM_OC_Init.OCMode=TIM_OCMODE_PWM2;
	TIM_OC_Init.OCPolarity=TIM_OCPOLARITY_LOW;
//	TIM_OC_Init.OCMode=TIM_OCMODE_PWM1;
//	TIM_OC_Init.OCPolarity=TIM_OCPOLARITY_HIGH;
	TIM_OC_Init.Pulse=50;
	if(HAL_TIM_PWM_ConfigChannel(&TIM_HandInit,&TIM_OC_Init,TIM_CHANNEL_2)!=HAL_OK){
		OLED_ShowChar(0,20,'B',16);
		OLED_UpData();
	}
	if(HAL_TIM_PWM_Start(&TIM_HandInit,TIM_CHANNEL_2)!=HAL_OK){
		OLED_ShowChar(0,40,'C',16);
		OLED_UpData();
	}
}

void TB6612_Init(void){
	__HAL_RCC_GPIOA_CLK_ENABLE();
	
	GPIO_InitTypeDef GPIO_Init;
	GPIO_Init.Mode=GPIO_MODE_OUTPUT_PP;//�������
	GPIO_Init.Pin=GPIO_PIN_4|GPIO_PIN_5;
	GPIO_Init.Pull=GPIO_NOPULL;
	GPIO_Init.Speed=GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOA,&GPIO_Init);
	//��ת AIN1��A4���1 AIN2��A5���0
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_RESET);
}

void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim){
//	if(htim->Instance==TIM2){
		__HAL_RCC_GPIOA_CLK_ENABLE();
		__HAL_RCC_TIM2_CLK_ENABLE();
		GPIO_InitTypeDef GPIO_Init;
		GPIO_Init.Mode=GPIO_MODE_AF_PP;//���츴�����
		GPIO_Init.Pin=GPIO_PIN_1;
		GPIO_Init.Pull=GPIO_NOPULL;
		GPIO_Init.Speed=GPIO_SPEED_FREQ_HIGH;
		HAL_GPIO_Init(GPIOA,&GPIO_Init);
		
//	}
}
