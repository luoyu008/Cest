#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void game() {
	char qipan[ROW][COL] = { 0 };
	int row = ROW;
	int col = COL;
	char c=0;
	//初始化棋盘
	Initqipan(qipan, row, col);
	//打印棋盘
	Displayqipan(qipan, row, col);
	while (1) {
		//玩家下棋
		Player(qipan, row, col);
		Displayqipan(qipan, row, col);
		//判断输赢
		c = Judge(qipan, row, col);
		if (c!='c')
		{
			break;
		}
		//电脑下棋
		Computer(qipan, row, col);
		//打印棋盘
		Displayqipan(qipan, row, col);
		//判断输赢
		c = Judge(qipan, row, col);
		if (c !='c')
		{
			break;
		}
	}
	if (c=='*')
	{
		printf("玩家赢\n");
	}
	else if (c=='#')
	{
		printf("电脑赢\n");
	}
	else if (c=='q')
	{
		printf("平局\n");
	}
	Displayqipan(qipan, row, col);
}
//打印菜单
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
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，重新输入\n");
			break;
		}
	} while (a);
	return 0;
}
