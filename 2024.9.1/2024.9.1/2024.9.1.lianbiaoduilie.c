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
		printf("��Ϊ��������\n");
	}
	else {
		printf("��������Ϊ%d\n", y);
	}
	QUEUEPop(&p);
	y = QUEUESize(&p);
	if (y == -1) {
		printf("��Ϊ��������\n");
	}
	else {
		printf("��������Ϊ%d\n", y);
	}
	QUEUEPop(&p);
	y = QUEUESize(&p);
	if (y == -1) {
		printf("��Ϊ��������\n");
	}
	else {
		printf("��������Ϊ%d\n", y);
	}
	QUEUEPop(&p);
	y = QUEUESize(&p);
	if (y == -1) {
		printf("��Ϊ��������\n");
	}
	else {
		printf("��������Ϊ%d\n", y);
	}
	QUEUEDestroy(&p);
}
int main() {
	text();
	return 0;
}