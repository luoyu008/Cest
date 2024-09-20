#include "buzzer.h"
void Buzzer(unsigned int ms){
	unsigned int i=0;
for(i=0;i<ms;i++){
			buz=!buz;
			delay(1);
		}
}