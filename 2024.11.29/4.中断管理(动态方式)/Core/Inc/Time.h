#ifndef __TIME_H__
#define __TIME_H__
extern TIM_HandleTypeDef Time2_FreeRtosInit;
extern TIM_HandleTypeDef Time3_FreeRtosInit;
extern uint32_t count2;
extern uint32_t count3;
void Time2_Init(void);
void Time3_Init(void);

#endif

