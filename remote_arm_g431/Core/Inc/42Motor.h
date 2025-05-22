#ifndef __42MOTOR_H__
#define __42MOTOR_H__
void Motoe_42Init(void);
void Motor_42_W_ENABLE(uint8_t en);
void Motor_42_W_DIR(uint8_t en);
#define PUL_Signal 		GPIO_PIN_3
#define ENABLE_Signal 	GPIO_PIN_2
#define DIR_Signal 		GPIO_PIN_1
#endif 

