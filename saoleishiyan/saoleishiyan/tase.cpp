#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void menu() {
	printf("****************\n");
	printf("*****1.play*****\n");
	printf("*****0.exit*****\n");
	printf("****************\n");
}
void game() {
	char lei[ROWS][COLS];
	char pan[ROWS][COLS];
	//��ʼ������
	init(lei,ROW,COL,'0');
	//��ʼ����ʾ��
	init(pan, ROW, COL, '*');
	//Display(lei, ROW, COL);
	//����
	Setlei(lei,ROW,COL);
	//Display(lei, ROW, COL);

	//��ʾ��Ϸ��
	Display(pan, ROW, COL);
	//����
	while (1) {
		play(lei, pan, ROW, COL);
		//Display(pan, ROW, COL);
		int c = juge(lei, pan, ROW, COL);
		if (c == LEISHU) {
			printf("��ϲ�㣬���׳ɹ�\n");
			break;
		}
	}


}
int main() {
	srand((unsigned int)time(NULL));
	int inpute;
	do
	{
		menu();
		scanf("%d", &inpute);
		switch (inpute)
		{case 1:
			game();
			break;
		case 0:
			printf("��Ϸ�˳�\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (inpute);
	return 0;
}