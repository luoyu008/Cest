#include "leddms.h"
void leddms1(unsigned char num){
	unsigned int i=0;
	for(i=0;i<8;i++){
		SER=num>>7;
		num=num<<1;
		SRCLK=0;
		delay(1);
		SRCLK=1;
	}
	RCLK_=0;

	RCLK_=1;
}