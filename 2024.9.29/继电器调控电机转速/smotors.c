#include "smotore.h"
void smotors_Start(){
	IN1=1;IN2=1;IN3=1;IN4=1;
}
void smotors_Stop(){
	IN1=0;IN2=1;IN3=1;IN4=1;
}