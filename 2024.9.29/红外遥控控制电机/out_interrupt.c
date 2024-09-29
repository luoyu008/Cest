#include "out_interrupt.h"
unsigned char state;//��ƽ״̬
unsigned int count;//������0�Ƶ���
unsigned char ARR[4];//����֮����ĸ����洢
unsigned char date;//�����±�
unsigned char address;//��ַ��
unsigned char commend;//������
unsigned char dateflage;//�õ����ݵı�־
unsigned char repeatflage;//�����ı�־
//unsigned char i,j;//iΪ�ĸ�����ѭ����jΪ��λ�ֽ�ѭ��
void out_Init()
{
	IT0=1;
	IE0=0;
	EX0=1;
	EA=1;
	PX0=1;
}
unsigned char out0_getdateflage(){
	if(dateflage){
		dateflage=0;
		return 1;
	}
	return 0;
}
unsigned char out0_getrepeatflage(){
	if(repeatflage)
	{
		repeatflage=0;
		return 1;
	}
	return 0;
}
unsigned char out0_returnadd()//���ص�ַ��
{
	return address;
}
unsigned char out0_returncom()//����������
{
	return commend;
}
void out0() interrupt 0
{
	if(state==0){//����״̬
		time0_set(0);//���ü�����0��0��ʼ����
		time0_con(1);//���ü�����0��ʼ����
		state=1;//ת��Ϊ״̬1 ���յ������ź�״̬
	}
	else if(state==1){
		count=time0_return();
		time0_set(0);
		if(count>=12442-500&&count<=12442+500){//��count��9ms+4.5ms������Χ֮��ת��Ϊ״̬2
			//����ʼ����״̬
			state=2;
		}
		else if(count>=10368-500&&count<=10368+500){//����9ms+2.25ms������Χ֮��ת��Ϊ״̬0
			//�����½����ź�״̬	
			repeatflage=1;
			time0_con(0);//�رռ�����
			state=0;
		}else
		{
			state=1;
		}
		}
	else if(state==2){
//		for(i=0;i<4;i++){
//			for(j=0;j<8;j++){
				count=time0_return();
				time0_set(0);
				if(count>=2074-500&&count<=2074+500){//�յ�����1
//					ARR[i]|=(0x01<<j);
				ARR[date/8]|=(0x01<<(date%8));
					date++;
				}
				else if(count>=1032-500&&count<=1032+500){//�յ�����0
//					ARR[i]&=~(0x01<<j);
				ARR[date/8]&=~(0x01<<(date%8));
					date++;
				}
				else{//��û���յ�����1Ҳû���յ�����0 
				date=0;
				state=1;
				}
//			}
//		}
				if(date>=32){
		date=0;
		if((ARR[0]==~ARR[1])&&(ARR[2]==~ARR[3])){	P2=0;
			//�ж������Ƿ���ȷ
		address=ARR[0];
		commend=ARR[2];
			dateflage=1;
		}
		time0_con(0);
		state=0;
	}
	}
}