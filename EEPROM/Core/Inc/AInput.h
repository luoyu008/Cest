#ifndef __AINPUT_H__
#define __AINPUT_H__
extern TIM_HandleTypeDef TIM2_HandInit;
extern TIM_SlaveConfigTypeDef TIM2_SlaveInit;
extern TIM_IC_InitTypeDef TIM2_ICCHInit;
extern uint16_t all;
extern uint16_t high;
extern uint16_t empty;
void AInput_Init(void);

#endif 
