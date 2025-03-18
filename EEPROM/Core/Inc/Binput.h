#ifndef __BINPUT_H__
#define __BINPUT_H__
extern TIM_HandleTypeDef TIM3_HandInit;
extern TIM_SlaveConfigTypeDef TIM3_SlaveInit;
extern TIM_IC_InitTypeDef TIM3_ICCHInit;
extern TIM_ClockConfigTypeDef sClockSourceConfig3;
extern TIM_MasterConfigTypeDef sMasterConfig3;
extern uint16_t all1;
extern uint16_t high1;
extern uint16_t empty1;
void BInput_Init(void);


#endif 
