#include "juzhen.h"

void main(){
	unsigned int pass=9527;
	unsigned char location=4;
	unsigned int my_pass=0;
	unsigned char key=0;
	LCD_Init();
	LCD_ShowString(1,1,"PassWord:");
	LCD_ShowString(2,1,"0000");
	while(1){
		key=retkey();
		delay(8);
		if(key){
			if(key<=10){
				if(location>0){
			my_pass=(my_pass)*10+key%10;
			LCD_ShowNum(2,location,my_pass,numlen(my_pass));
			(location)--;
				}
			}
			if(key==11){
			location=4;
			LCD_WriteCommand(0x01);
			LCD_ShowString(1,1,"PassWord:");
			LCD_ShowString(2,1,"0000");
			my_pass=0;
			}
			delay(5);
			if(my_pass==pass&&location==0){
			LCD_ShowString(1,11,"ok");
			}
			if(my_pass!=pass&&location==0){
			LCD_ShowString(1,11,"error");
			}
		}
	}
}
//		xianshi(retkey(),&pass,&location,&my_pass);
//		delay(5);
//		judge(pass,my_pass,location);
//		delay(5);
//	}
//}
//	P1_3=0;P1_2=1;P1_1=1;P1_0=1;
//		if(P1_7==0&&P1_6==1&&P1_5==1&&P1_4==1){
//			my_pass=my_pass*10+1;
//			LCD_ShowNum(2,location,my_pass,numlen(my_pass));
//			location--;
//			if(my_pass==pass&&location==0){
//			LCD_ShowString(1,11,"ok");
//			}
//			if(my_pass!=pass&&location==0){
//			LCD_ShowString(1,11,"error");
//			}
//		}
//		delay(10);
//		if(P1_7==1&&P1_6==0&&P1_5==1&&P1_4==1){
//			my_pass=my_pass*10+5;
//			LCD_ShowNum(2,location,my_pass,numlen(my_pass));
//			location--;
//			if(my_pass==pass&&location==0){
//			LCD_ShowString(1,11,"ok");
//			}
//			if(my_pass!=pass&&location==0){
//			LCD_ShowString(1,11,"error");
//			}
//		}
//		delay(10);
//		if(P1_7==1&&P1_6==1&&P1_5==0&&P1_4==1){
//			my_pass=my_pass*10+9;
//			LCD_ShowNum(2,location,my_pass,numlen(my_pass));
//			location--;
//			if(my_pass==pass&&location==0){
//			LCD_ShowString(1,11,"ok");
//			}
//			if(my_pass!=pass&&location==0){
//			LCD_ShowString(1,11,"error");
//			}
//		}
//		delay(10);
//		if(P1_7==1&&P1_6==1&&P1_5==1&&P1_4==0){
//			LCD_WriteCommand(0x01);
//			LCD_ShowString(1,1,"S13");
//		}
//		delay(10);
//		P1_3=1;P1_2=0;P1_1=1;P1_0=1;
//		if(P1_7==0&&P1_6==1&&P1_5==1&&P1_4==1){
//			my_pass=my_pass*10+2;
//			LCD_ShowNum(2,location,my_pass,numlen(my_pass));
//			location--;
//			if(my_pass==pass&&location==0){
//			LCD_ShowString(1,11,"ok");
//			}
//			if(my_pass!=pass&&location==0){
//			LCD_ShowString(1,11,"error");
//			}
//		}
//		delay(10);
//		if(P1_7==1&&P1_6==0&&P1_5==1&&P1_4==1){
//			my_pass=my_pass*10+6;
//			LCD_ShowNum(2,location,my_pass,numlen(my_pass));
//			location--;
//			if(my_pass==pass&&location==0){
//			LCD_ShowString(1,11,"ok");
//			}
//			if(my_pass!=pass&&location==0){
//			LCD_ShowString(1,11,"error");
//			}
//		}
//		delay(10);
//		if(P1_7==1&&P1_6==1&&P1_5==0&&P1_4==1){
//			my_pass=my_pass*10+0;
//			LCD_ShowNum(2,location,my_pass,numlen(my_pass));
//			location--;
//			if(my_pass==pass&&location==0){
//			LCD_ShowString(1,11,"ok");
//			}
//			if(my_pass!=pass&&location==0){
//			LCD_ShowString(1,11,"error");
//			}
//		}
//		delay(10);
//		if(P1_7==1&&P1_6==1&&P1_5==1&&P1_4==0){
//			LCD_WriteCommand(0x01);
//			LCD_ShowString(1,1,"S14");
//		}
//		delay(10);
//		P1_3=1;P1_2=1;P1_1=0;P1_0=1;
//		if(P1_7==0&&P1_6==1&&P1_5==1&&P1_4==1){
//			my_pass=my_pass*10+3;
//			LCD_ShowNum(2,location,my_pass,numlen(my_pass));
//			location--;
//			if(my_pass==pass&&location==0){
//			LCD_ShowString(1,11,"ok");
//			}
//			if(my_pass!=pass&&location==0){
//			LCD_ShowString(1,11,"error");
//			}
//		}
//		delay(10);
//		if(P1_7==1&&P1_6==0&&P1_5==1&&P1_4==1){
//			my_pass=my_pass*10+7;
//			LCD_ShowNum(2,location,my_pass,numlen(my_pass));
//			location--;
//			if(my_pass==pass&&location==0){
//			LCD_ShowString(1,11,"ok");
//			}
//			if(my_pass!=pass&&location==0){
//			LCD_ShowString(1,11,"error");
//			}
//		}
//		delay(10);
//		if(P1_7==1&&P1_6==1&&P1_5==0&&P1_4==1){
//			location=4;
//			LCD_WriteCommand(0x01);
//			LCD_ShowString(1,1,"PassWord:");
//			LCD_ShowString(2,1,"0000");
//			my_pass=0;
//		}
//		if(P1_7==1&&P1_6==1&&P1_5==1&&P1_4==0){
//			LCD_WriteCommand(0x01);
//			LCD_ShowString(1,1,"S15");
//		}
//		delay(10);
//		P1_3=1;P1_2=1;P1_1=1;P1_0=0;
//		if(P1_7==0&&P1_6==1&&P1_5==1&&P1_4==1){
//			my_pass=my_pass*10+4;
//			LCD_ShowNum(2,location,my_pass,numlen(my_pass));
//			location--;
//			if(my_pass==pass&&location==0){
//			LCD_ShowString(1,11,"ok");
//			}
//			if(my_pass!=pass&&location==0){
//			LCD_ShowString(1,11,"error");
//			}
//		}
//		delay(10);
//		if(P1_7==1&&P1_6==0&&P1_5==1&&P1_4==1){
//			my_pass=my_pass*10+8;
//			LCD_ShowNum(2,location,my_pass,numlen(my_pass));
//			location--;
//			if(my_pass==pass&&location==0){
//			LCD_ShowString(1,11,"ok");
//			}
//			if(my_pass!=pass&&location==0){
//			LCD_ShowString(1,11,"error");
//			}
//		}
//		delay(10);
//		if(P1_7==1&&P1_6==1&&P1_5==0&&P1_4==1){
//			LCD_WriteCommand(0x01);
//			LCD_ShowString(1,1,"S12");
//		}
//		if(P1_7==1&&P1_6==1&&P1_5==1&&P1_4==0){
//			LCD_WriteCommand(0x01);
//			LCD_ShowString(1,1,"S16");
//		}
//	}
//}