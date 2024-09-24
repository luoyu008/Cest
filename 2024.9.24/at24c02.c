#include "at24c02.h"

void at24c02_Writebyte(unsigned char wordaddress,date){
	unsigned char res=0; 
	iic_Start();
	iic_Send(ataddress);
	iic_Receiveres();
		iic_Send(wordaddress);
		iic_Receiveres();
		iic_Send(date);
		iic_Receiveres();
		iic_Stop();	
}
unsigned char at24c02_Readbyte(unsigned char wordaddress){
 unsigned char date=0;
	iic_Start();
	iic_Send(ataddress);
	iic_Receiveres();
	iic_Send(wordaddress);
	iic_Receiveres();
	iic_Start();
	iic_Send(ataddress|0x01);
	iic_Receiveres();
	date=iic_Receive();
	iic_Sendres(1);
	iic_Stop();
	return date;
}