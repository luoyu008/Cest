#include "rekey.h"
#include "delay.h"
unsigned char  rekey(){
	unsigned char key=0;
	if(P3_1==0){
		delay(1);
	while(P3_1==0);
		delay(1);
		key=1;
	}
	if(P3_0==0){
		delay(1);
	while(P3_0==0);
		delay(1);
		key=2;
	}
	if(P3_2==0){
		delay(1);
	while(P3_2==0);
		delay(1);
		key=3;
	}
	if(P3_3==0){
		delay(1);
	while(P3_3==0);
		delay(1);
		key=4;
	}
	return key;
}