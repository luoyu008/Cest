#ifndef __CANLOOPTEST_H__
#define __CANLOOPTEST_H__
extern CAN_InitTypeDef CAN_LoopTestInit;
extern CAN_FilterInitTypeDef CAN_LoopTestFilterInit;
extern CanRxMsg CAN_RxLoopTestInit;
extern CanRxMsg CAN_RxLoopTestInit1;
extern uint8_t RxFlage;
extern uint8_t RxFlage1;
void CANLoopTest_Init(void);
void CANLoopTest_NormalMode(void);
void CANLoopTest_Send(CanTxMsg* CAN_LoopTest);
uint8_t Receive_Flag(void);
uint8_t Receive_Flag1(void);
void CANLoopTest_Read(void);
void CANLoopTest_Read1(void);
#endif

