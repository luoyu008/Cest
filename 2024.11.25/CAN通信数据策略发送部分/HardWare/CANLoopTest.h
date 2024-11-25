#ifndef __CANLOOPTEST_H__
#define __CANLOOPTEST_H__
extern CAN_InitTypeDef CAN_LoopTestInit;
extern CAN_FilterInitTypeDef CAN_LoopTestFilterInit;
extern CanRxMsg CAN_RxLoopTestInit;
extern uint8_t RxFlage;
void CANLoopTest_Init(void);
void CANLoopTest_NormalMode(void);
void CANLoopTest_Send(CanTxMsg* CAN_LoopTest);
uint8_t Receive_Flag(void);
void CANLoopTest_Read(void);
#endif

