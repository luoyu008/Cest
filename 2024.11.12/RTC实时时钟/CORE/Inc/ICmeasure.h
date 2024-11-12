#ifndef __ICMEASURE_H__
#define __CIMEASURE_H__
extern uint16_t g_state;
extern uint16_t g_count;
extern TIM_HandleTypeDef TIM_IC_HandInit;
extern TIM_IC_InitTypeDef TIM_IC_Init;
void ICmeasure_Init(void);
#endif
