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
	//初始化雷盘
	init(lei,ROW,COL,'0');
	//初始化显示盘
	init(pan, ROW, COL, '*');
	//Display(lei, ROW, COL);
	//放雷
	Setlei(lei,ROW,COL);
	//Display(lei, ROW, COL);

	//显示游戏盘
	Display(pan, ROW, COL);
	//下棋
	while (1) {
		play(lei, pan, ROW, COL);
		//Display(pan, ROW, COL);
		int c = juge(lei, pan, ROW, COL);
		if (c == LEISHU) {
			printf("恭喜你，排雷成功\n");
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
			printf("游戏退出\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (inpute);
	return 0;
}