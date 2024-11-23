#ifndef __CANLOOPTEST_H__
#define __CANLOOPTEST_H__

void CANLoopTest_Init(void);
void CANLoopTest_NormalMode(void);
void CANLoopTest_Send(CanTxMsg* CAN_LoopTest);
uint8_t Receive_Flag(void);
void CANLoopTest_Read(CanRxMsg* CAN_LoopTestInit);
#endif

