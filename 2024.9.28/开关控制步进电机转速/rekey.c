#include "rekey.h"
unsigned K;
unsigned char rekey_return(){
	unsigned char temp=0;
	temp=K;
	K=0;
	return temp;
}
unsigned char  rekey(){
	unsigned char key=0;
	if(P3_1==0){
		key=1;
	}
	if(P3_0==0){
		key=2;
	}
	if(P3_2==0){
		key=3;
	}
	if(P3_3==0){
		key=4;
	}
	return key;
}

void rekey_loop(){
	static unsigned char  cur=0,prev=0;
	prev=cur;
	cur=rekey();
	if(prev==1&&cur==0){
	K=1;
	}
	if(prev==2&&cur==0){
	K=2;
	}
	if(prev==3&&cur==0){
	K=3;
	}
	if(prev==4&&cur==0){
	K=4;
	}
}
