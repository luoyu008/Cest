#ifndef __ADVANCEDTIMICPWM_H__
#define __ADVANCEDTIMICPWM_H__
extern TIM_HandleTypeDef TIM_AdvancedICPWM;
extern TIM_IC_InitTypeDef TIM_IC_AdvancedPWM;
extern TIM_SlaveConfigTypeDef TIM_SlaveAdvancedICPWMInit;
extern uint16_t count4;
extern uint16_t high;
extern uint16_t all;
extern uint8_t state9;
void ADVANCEDTIMICPWM_Init(void);
void ICPWM_Reset(void);
#endif
