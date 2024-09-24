#include <REGX52.H>
#include "iic.h"
void iic_Start(){
	SDA=1;
	SCL=1;
	SDA=0;
	SCL=0;
}
void iic_Stop(){
	SDA=0;
	SCL=1;
	SDA=1;
}
void iic_Send(unsigned char date){
	unsigned char i=0;
	for(i=0;i<8;i++){
	SDA=date&(0x80>>i);
	SCL=1;
	SCL=0;
	}
}
unsigned char  iic_Receive(){
	unsigned char date=0,i=0;
	SDA=1;
	for(i=0;i<8;i++){
	SCL=1;
	if(SDA)date|=(0x80>>i);
	SCL=0;
	}
	return date;
}
void iic_Sendres(unsigned char res){
	SDA=res;
	SCL=1;
	SCL=0;
}
unsigned char  iic_Receiveres(){
	unsigned char res=0;
	SDA=1;
	SCL=1;
	res=SDA;
	SCL=0;
	return res;
}