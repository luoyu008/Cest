#ifndef __DIFPHASEPWM_H__
#define __DIFPHASEPWM_H__
extern TIM_HandleTypeDef TIM_DifPhasePwmInit;
extern TIM_OC_InitTypeDef TIM_OC_DifPhasePwmInit;
void DifPhasePwm_Init(void);
void DifPhasePwm_SetPhase(uint16_t Phase,uint32_t Channel);
#endif
