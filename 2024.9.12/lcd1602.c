#include"lcd1602.h"
sbit LCD_RS=P2^6;
sbit LCD_RW=P2^5;
sbit LCD_RE=P2^7;
#define LCD_DATE P0
//��ʱ����
void delay(unsigned int count){
	unsigned char i,j;
	i=2;
	j=199;
	while(count--){
	do
	{
		while(--j);
	}while(--i);
		
	}
}
//�����
void LCDCMD(unsigned char num){
	LCD_RS=0;
	LCD_RW=0;
	LCD_RE=0;
	P0=num;
	LCD_RE=1;;
	delay(3);
	LCD_RE=0;
	delay(3);
}
//��ʼ��
void LCD_Init(){
	LCDCMD(0x38);//��������8λ����ʾ2�У�5*7����/�ַ�
	LCDCMD(0x0C);//��ʾ���ܿ����޹�꣬�����˸
	LCDCMD(0x06);//д�������ݺ������ƣ���ʾ������
	LCDCMD(0x01);//����
}
//����д��
void LCD_WRITE_CHAR(unsigned char date){
	LCD_RS=1;
	LCD_RW=0;
	LCD_DATE=date;
	delay(3);
	LCD_RE=1;
	delay(3);
	LCD_RE=0;
}
int pow(int x,int y){
	int result=1;
	int i=0;
	for(i;i<y;i++){
		result=result*x;
	}
	return result;
}
//����λ��
void LCD_SET(unsigned char line,unsigned char column){
	if(line==1){
	LCDCMD(0x80|(column-1));
	}
	if(line==2){
	LCDCMD(0x80|(column-1+0x40));
	}
}
//��ʾ����
void LCD_SHOWSTRING(unsigned char line,unsigned char column,char* str){
	
	unsigned char location;
	if(line>1||column>15)
		return;
	if(line<1){
	while(*str!='\0'){
		if(location<16-column+1){
		LCDCMD(0x80+location+column-1);
		}
		else{
		LCDCMD(0x80+0x40+location+column-16-1);
		}
		LCD_WRITE_CHAR(*str);
		str++;
		location++;
	}
	}
	else{
	while(*str!='\0'){
		if(location<16-column+1){
		LCDCMD(0x80+0x40+location+column-1);
		}
		else{
		LCDCMD(0x80+location+column-16-1);
		}
		LCD_WRITE_CHAR(*str);
		str++;
		location++;
	}
	}
}
//���ֳ���
int length(int num){
	int length=0;
	while(num>0){
	num=num/10;
		length++;
	}
	return length;
}
//��ʾ����
void LCD_SHOWNUM(unsigned char line,unsigned char column,unsigned int num){
	unsigned char len=length(num);
	unsigned int i=0;
	unsigned char j=1;
	LCD_SET(line,column);
	if(line==1){
	for(i=len;i>0;i--){
		if(i>16-column){
	LCD_WRITE_CHAR(num/pow(10,i-1)%10+'0');
		}
		else{
		LCD_SET(2,j++);
		LCD_WRITE_CHAR(num/pow(10,i-1)%10+'0');
		}
	}
}
	else{
		j=1;
		for(i=len;i>0;i--){
		if(i>16-column){
	LCD_WRITE_CHAR(num/pow(10,i-1)%10+'0');
		}
		else{
		LCD_SET(1,j++);
		LCD_WRITE_CHAR(num/pow(10,i-1)%10+'0');
		}
	}
	}
}


//��ʾ�з�������
void LCD_SHOWSIGNEDNNUM(unsigned char line,unsigned char column,int num){
		unsigned int i=0;
		unsigned int len=0;
		unsigned int num1=0;
		LCD_SET(line,column);
		if(num>0){
		LCD_WRITE_CHAR('+');
			num1=num;
			len=length(num1);
		}
		else{
		LCD_WRITE_CHAR('-');
			num1=-num;
			len=length(num1);
		}
		for(i=len;i>0;i--){
			LCD_WRITE_CHAR(num1/pow(10,i-1)%10+'0');
		}
}