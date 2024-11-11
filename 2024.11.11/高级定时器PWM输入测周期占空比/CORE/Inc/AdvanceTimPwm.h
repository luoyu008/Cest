#ifndef __ADVANCETIMPWM_H__
#define __ADCANCETIMPWM_H__

extern TIM_HandleTypeDef TIM_AdvanceTimPwmHandInit;
extern TIM_OC_InitTypeDef TIM_OC_AdvanceTimPwmInit;
void AdvanceTimPwm_Init(void);
void AdvanceTimPwm_Set(uint8_t NPWm);
#endif

