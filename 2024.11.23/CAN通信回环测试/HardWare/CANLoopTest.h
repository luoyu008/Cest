#ifndef __CANLOOPTEST_H__
#define __CANLOOPTEST_H__

void CANLoopTest_Init(void);
void CANLoopTest_NormalMode(void);
void CANLoopTest_Send(uint32_t ID,uint8_t length,uint8_t* Data);
uint8_t Receive_Flag(void);
void CANLoopTest_Read(uint32_t* ID,uint8_t* length,uint8_t* Data);
#endif

