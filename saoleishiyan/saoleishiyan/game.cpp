#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
//��ʼ��
void init(char str[ROWS][COLS], int rows, int cols,char set) {
	int i = 0;
	int j = 0;
	for (i = 0; i < ROWS;i++) {
		for (j = 0; j < COLS;j++) {
			str[i][j] = set;
		}
	}
}
//��ʾ
void Display(char str[ROWS][COLS], int rows, int cols) {
	int i = 0;
	int j = 0;
	printf("--------ɨ��--------\n");
	for (i = 0; i <= ROW; i++) {
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= ROW; i++) {
		printf("%d ", i);
		for ( j = 0; j < COL; j++)
		{
			printf("%c ", str[i][j]);
		}
		printf("\n");
	}
	printf("--------ɨ��--------\n");


}
//����
void Setlei(char str[ROWS][COLS], int rows, int cols) {
	int count = 0;
	while (count<LEISHU) {
		int x = rand() % ROW + 1;
		int y = rand() % COL + 1;
		if (x >= 1 && x <= ROW && y > 1 && y <= COL) {
			if (str[x ][y] != '1') {
			str[x][y] = '1';
			count++;
		}
		}
	}
}
//����
int  find(char str[ROWS][COLS], int a, int b) {
	int c = 0;
	int i = 0;
	int j = 0;
	for (i = a - 1; i <= a + 1; i++) {
		for ( j = b-1; j <=b+1; j++)
		{
			if (str[i][j] == '1')
				c++;
		}
	}
	return c;
}
//��չ��
//void zhankai(char str[ROWS][COLS], char str1[ROWS][COLS], int a, int b){
//	str1[a][b] == ' ';
//	if (str[a][b] == '0') {
//		for (int  i = a-1; i <=a+1; i++)
//		{
//			for (int j = b - 1; j <= b + 1; j++) {
//				if (a >= 1 && a <= ROW && b >= 1 && b <= COL && str1[a][b] == '*'&&str[a][b]=='0') {
//					str1[a][b] = find(str, a, b)+'0';
//					if (str1[a][b] == '0') {
//						zhankai(str, str1, a, b);
//					}
//				}
//			}
//		}
//	}
//}
void DfsMine(char str[ROWS][COLS], char str1[ROWS][COLS], int a, int b)
{
	int count = find(str, a, b);
	str1[a][b] = count + '0';
	if (count != 0)
	{
		return;
	}
	int xx[] = { 1,1, 1 ,-1,-1,-1,0, 0 };
	int yy[] = { 1,0,-1, 0, 1, -1 ,1,-1 };
	int i = 0;
	for (i = 0; i < 8; i++)
	{
		int dx = a + xx[i];
		int dy = b + yy[i];
		if (dx >= 1 && dx <= ROW && dy >= 1 && dy <= COL && str[dx][dy] == '0' && str1[dx][dy] == '*')
		{
			DfsMine(str, str1, dx, dy);
		}
	}
}
void Lzhankai() {

}
//����
void play(char str[ROWS][COLS], char str1[ROWS][COLS], int rows, int cols) {
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 1;
	int e = 1;
	while (c < ROW * COL - LEISHU) {
		printf("��������\"5 5\"λ��\n");
		scanf("%d %d", &a, &b);
		if (a >= 1 && a <= rows && b >= 1 && b <= cols) {
			if (str[a][b - 1] == '1') {
				printf("�㱻ը���ˣ���Ϸ����\n");
				Display(str, ROW, COL);
				break;
			}
			else {
				str1[a][b - 1] = find(str, a, b) + '0';
				DfsMine(str,str1,a,b-1);
				Display(str1, ROW, COL);
				c++;
			}
		}
		else
		{
			printf("�����������������\n");
		}
		for ( d = 1; d <=ROW; d++)
		{
			for (e = 1; e <= COL; e++) {
				if (str1[d][e] == '*') {
					c++;
				}
			}
		}
			if (c == LEISHU) {
				printf("��ϲ�㣬���׳ɹ�\n");
			}
		
	}
}
//�ж�
int juge(char str[ROWS][COLS], char str1[ROWS][COLS], int a, int b) {
	int c = 0;
	for (int d = 1; d <= ROW; d++)
	{
		for (int e = 1; e <= COL; e++) {
			if (str1[d][e] == '*') {
				c++;
			}
		}
	}
	return c;

}
