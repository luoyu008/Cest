#include "LCD1602.h"
void LCD1602_Delay1ms(void)	//@11.0592MHz
{
	unsigned char data i, j;

	_nop_();
	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
}
int pow(unsigned char num, unsigned char num2) {
	unsigned int i = 0;
	int temp = 1;
	for (i = 0; i < num2 ; i++) {
		temp *= num;
	}
	return  temp;
}
void LCD1602_Commend(unsigned char commend){//写指令
	RS=0;
	RW=0;
	port=commend;
	EN=1;
	LCD1602_Delay1ms();
	//port=commend;
	EN=0;
	LCD1602_Delay1ms();
}
void LCD1602_Data(unsigned char Data){//写数据
	RS=1;
	RW=0;
	port=Data;
	EN=1;
	LCD1602_Delay1ms();
	EN=0;
	LCD1602_Delay1ms();
}
void LCD1602_Init(){		//初始化
	LCD1602_Commend(0x38);//总数据线8位 显示2行 5*7点阵/字符
	LCD1602_Commend(0x0C);//显示开 无光标 光标不闪烁
	LCD1602_Commend(0x06);//读写操作后光标加一 画面不动
	LCD1602_Commend(0x01);//清屏
}
//显示字符
void LCD1602_ShowChar(unsigned char row,unsigned char col,char s){
	if(row==1){
		LCD1602_Commend(0x80|(col-1));
	}
	else if(row==2){
		LCD1602_Commend(0x80|(col-1)+0x40);
	}
	LCD1602_Data(s);
}
//显示字符串
void LCD1602_ShowString(unsigned char row,unsigned char col,const char* str){
	unsigned char i=0;
	if(row==1){
		LCD1602_Commend(0x80|(col-1));
	}
	else if(row==2){
		LCD1602_Commend(0x80|(col-1)+0x40);
	}
	while(*(str+i)!='\0'){
		LCD1602_Data(*(str+i));
		i++;
	}
}
//显示数字
void LCD1602_ShowNum(unsigned char row,unsigned char col,unsigned int num,unsigned char length){
	unsigned char i=0; 
	if(row==1){
		LCD1602_Commend(0x80|(col-1));
	}
	else if(row==2){
		LCD1602_Commend(0x80|(col-1)+0x40);
	}
	for(i=length;i>0;i--){
	LCD1602_Data(num/pow(10,i-1)%10+'0');
	//num=num%pow(10,i-1);
	}
}
//显示有符号为的数字
void LCD1602_ShowSignedNum(unsigned char row,unsigned char col,int num,unsigned char length){
	unsigned char i=0;
	unsigned int num1;
	if(row==1){
		LCD1602_Commend(0x80|(col-1));
	}
	else if(row==2){
		LCD1602_Commend(0x80|(col-1)+0x40);
	}
	if(num>=0)
	{
		LCD1602_Data('+');
		num1=num;
	}
	else
	{
		LCD1602_Data('-');
		num1=-num;
	}
	for(i=length;i>0;i--)
	{
		LCD1602_Data(num1/pow(10,i-1)%10+'0');
	}

//	if(num<0){
//		LCD1602_Data('-');
//		num1=-num;
//	}
//	else
//	{
//		LCD1602_Data(' ');
//		num1=num;
//	}
//	for(i=length;i>0;i--){
//	LCD1602_Data(num1/pow(10,i-1)%10+'0');
//	//num=num%pow(10,i-1);
//	}
}
//显示二进制数
void LCD1602_BinNum(unsigned char row,unsigned char col,unsigned char num){
	unsigned char i=0;
	if(row==1){
		LCD1602_Commend(0x80|(col-1));
	}
	else if(row==2){
		LCD1602_Commend(0x80|(col-1)+0x40);
	}
	for(i=8;i>0;i--){
	LCD1602_Data(num/pow(2,i-1)%2+'0');
	}
}
//显示十六进制数
void LCD1602_HexNum(unsigned char row,unsigned char col,unsigned int num){
	unsigned char arr[8];
	unsigned char i=0;
	unsigned char temp=0;
	unsigned int num1;
	unsigned int num2;
	if(row==1){
		LCD1602_Commend(0x80|(col-1));
	}
	else if(row==2){
		LCD1602_Commend(0x80|(col-1)+0x40);
	}
	LCD1602_Data('0');
	LCD1602_Data('X');
	for(i=2;i>0;i--){
	temp=num/pow(16,i-1)%16;
		if(temp>=10){
		LCD1602_Data(temp-10+'A');
		}
		else {
		LCD1602_Data(temp+'0');
		}
	}
	for(i=7;i>=0;i--){
		arr[i]=num/pow(2,i)%2;
	}
	for(i=7;i>=4;i--){
	num1+=pow(2,i-4);
	}
	for(i=3;i>=0;i--){
	num2+=pow(2,i);
	}
//	 num1 = (num >> 4) & 0x0F;  // 高4位  
//   num2 = num & 0x0F;         // 低4位  
	if(num1>=10){
	num1=num1-10+'A';
	}
	else
	{
		num1+='0';
	}
	if(num2>=10){
	num2=num2-10+'A';
	}
	else
	{
	num2=num2+'0';
	}
	LCD1602_Data((unsigned char )num1);
	LCD1602_Data((unsigned char )num2);
}
