#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
//��ʼ������
void Initqipan(char qipan[ROW][COL], int row, int col) {
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			qipan[i][j] = ' ';
		}
	}
}
//��ӡ����
void Displayqipan(char qipan[ROW][COL], int row, int col) {
	int i = 0;
	for (i = 0; i < row; i++) {
		int j = 0;
		for (j = 0; j < col; j++) {
			printf(" %c ", qipan[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			int j = 0;
			for (j = 0; j < col; j++) {
				printf("---");
				if (j < col - 1) {
					printf("|");
				}
			}
			printf("\n");
		}
	}
}
//�������
void Player(char qipan[ROW][COL], int row, int col) {
	//printf("���������\n");
	int x = 0;
	int y = 0;
	//�ж�λ���Ƿ�Խ��
	while (1) {
		printf("���������\n");
		scanf("%d %d", &x, &y);
		if ((x > 0 && x <= row) && (y > 0 && y <= col)) {
			if (qipan[x - 1][y - 1] == ' ') {
				qipan[x - 1][y - 1] = '*';
				break;
			}
			else {
				printf("���걻ռ�ã�������\n");
			}
		}
		else {
			printf("�����������������\n");
		}
	}
}
//��������
void Computer(char qipan[ROW][COL], int row, int col) {
	printf("��������\n");
	int x = 0;
	int y = 0;
	while (1) {
		 x = rand() % row;
		 y = rand() % col;
		if (qipan[x][y] == ' ') {
			qipan[x][y] = '#';
			break;
		}
	}
}
//�ж�����������
int Full(char qipan[ROW][COL], int row, int col) {
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (qipan[i][j] == ' ') {
			return 0;
		}
		}
	}
	return 1;
}
//�ж���Ӯ ����* ���Ӯ #����Ӯ qƽ�� c����
char Judge(char qipan[ROW][COL], int row, int col) {
	int i = 0;
	int j = 0;
	//��
	for (i = 0; i < row; i++) {
		if ( qipan[i][0] == qipan[i][1] && qipan[i][1] == qipan[i][2]&&qipan[i][1]!=' ') {
			return qipan[i][1];
		}
	}
	//��
	for (i = 0; i < col; i++) {
		if (  qipan[0][i] == qipan[1][i] && qipan[1][i] == qipan[2][i]&&qipan[1][i]!=' ') {
			return qipan[1][i];
		}
	}
	//�Խ�
	if (qipan[1][1] == qipan[0][0] && qipan[1][1] == qipan[2][2] && qipan[1][1] != ' ') {
		return qipan [1][1];
	}
	else if (qipan[1][1] == qipan[0][2] && qipan[2][0] == qipan[1][1] && qipan[1][1] != ' ') {
		return qipan[1][1];
	}
	//ƽ��
	if (Full(qipan, row, col)) {
		return 'q';
	}
	return 'c';
}

