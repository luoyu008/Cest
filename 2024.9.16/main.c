#include "leddms.h"
#include "delay.h"
unsigned char col[]={0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};
unsigned char row[]={0x00,0x3C,0x42,0x42,0x3C,0x00,0x00,0x00};
void main(){
		unsigned char i=0;
		unsigned char j=0;
		for(j=1;j<=5;j++){
		for(i=7;i>=j;i--){
			P0=col[i];
				leddms1(row[j]);
				delay(50);
				leddms1(0x00);
			}
			leddms1(row[j]);
		}
		while(1){
			for(i=0;i<8;i++){
			P0=col[i];
				leddms1(row[i]);
				delay(1);
				leddms1(0x00);
			}
		}
//		P0=0x7F;
//		leddms1(0x00);
//			delay(10);
//			leddms1(0x00);
//		P0=0xbf;	
//		leddms1(0x7c);
//			delay(10);
//						leddms1(0x00);
//			P0=0xdf;	
//		leddms1(0x82);
//			delay(10);
//						leddms1(0x00);
//			P0=0xef;	
//		leddms1(0x82);
//			delay(10);
//						leddms1(0x00);
//			P0=0xf7;	
//		leddms1(0x82);
//			delay(10);
//						leddms1(0x00);
//			P0=0xfb;	
//		leddms1(0x7c);
//			delay(10);
//						leddms1(0x00);
//			P0=0xfd;	
//		leddms1(0x00);
//			delay(10);
//						leddms1(0x00);
//			P0=0xfe;	
//		leddms1(0x00);
//			delay(10);
//						leddms1(0x00);
//		}

}