#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void game() {
	char qipan[ROW][COL] = { 0 };
	int row = ROW;
	int col = COL;
	char c=0;
	//��ʼ������
	Initqipan(qipan, row, col);
	//��ӡ����
	Displayqipan(qipan, row, col);
	while (1) {
		//�������
		Player(qipan, row, col);
		Displayqipan(qipan, row, col);
		//�ж���Ӯ
		c = Judge(qipan, row, col);
		if (c!='c')
		{
			break;
		}
		//��������
		Computer(qipan, row, col);
		//��ӡ����
		Displayqipan(qipan, row, col);
		//�ж���Ӯ
		c = Judge(qipan, row, col);
		if (c !='c')
		{
			break;
		}
	}
	if (c=='*')
	{
		printf("���Ӯ\n");
	}
	else if (c=='#')
	{
		printf("����Ӯ\n");
	}
	else if (c=='q')
	{
		printf("ƽ��\n");
	}
	Displayqipan(qipan, row, col);
}
//��ӡ�˵�
void menu() {
	printf("***************\n*1.play 0.quit*\n***************\n");

}
int main() {
	int a = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		scanf("%d", &a);
		switch (a) {
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("���������������\n");
			break;
		}
	} while (a);
	return 0;
}
