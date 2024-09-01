#define _CRT_SECURE_NO_WARNINGS
#include"2024.9.1.lianbiaoduilie.h"
void text() {
	q p;
	QUEUEInit(&p);
	QUEUEPush(&p);
	QUEUEPush(&p);
	QUEUEPush(&p); 
	//datetype y=QUEUEFront(&p);
	datetype y=QUEUESize(&p);
	if (y == -1) {
		printf("队为空无数据\n");
	}
	else {
		printf("队数据量为%d\n", y);
	}
	QUEUEPop(&p);
	y = QUEUESize(&p);
	if (y == -1) {
		printf("队为空无数据\n");
	}
	else {
		printf("队数据量为%d\n", y);
	}
	QUEUEPop(&p);
	y = QUEUESize(&p);
	if (y == -1) {
		printf("队为空无数据\n");
	}
	else {
		printf("队数据量为%d\n", y);
	}
	QUEUEPop(&p);
	y = QUEUESize(&p);
	if (y == -1) {
		printf("队为空无数据\n");
	}
	else {
		printf("队数据量为%d\n", y);
	}
	QUEUEDestroy(&p);
}
int main() {
	text();
	return 0;
}