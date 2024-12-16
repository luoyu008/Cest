#ifndef __PWMMOTOR_H__
#define __PWMMOTOR_H__
extern TIM_HandleTypeDef TIM_HandInit;
extern TIM_OC_InitTypeDef TIM_OC_Init;
void PWM_Init(void);
void TB6612_Init(void);
#endif

