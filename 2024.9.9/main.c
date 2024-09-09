#include <REGX52.H>
void Delay(unsigned int count){
	unsigned char i,j;
	i=2;
	j=239;
	while(count--){
	do{
	while(--j);
	}while(--i);
}
	}
void main(){
	unsigned int temp=3;
	unsigned int count=0;
	P2=~(0x01);
	while(1){
		if(P3_1==0){
//			Delay(20);
//			while(P3_1==0);
//			Delay(20);
			Delay(20); 
      if (P3_1 == 0) {   
      while (P3_1 == 0);   
      Delay(20);
			count=(++count)%8;
			P2=~(0x01<<count);
//			temp=temp<<1;
		}
//		if(P2==0x80)
//			P2=0xFE;
	}
}
	}