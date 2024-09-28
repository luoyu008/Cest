#include "smotore.h"
void smotors_Start(){
	DA=1;IN2=1;IN3=1;IN4=1;
}
void smotors_Stop(){
	DA=0;IN2=1;IN3=1;IN4=1;
}