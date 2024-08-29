#define _CRT_SECURE_NO_WARNINGS
#include"2024.8.28.h"
void test() {
	SL* sl = NULL;
	//SListInit(&sl);
	/*SListPushBack(&sl);
	SListPushBack(&sl);
	SListPushBack(&sl);
	SListPushBack(&sl);*/
	//SListPushBack(&sl);
	//SListPushBack(&sl);
	//SListPushFront(&sl);
	SListPushBack(&sl);
	SListPushBack(&sl);
	SListPushBack(&sl); 
	SListdestory(&sl);
	//SListEraseF(&sl);
	//SListErase(&sl);
	//SListInsertF(&sl);
	//SListInsertB(&sl);
	/*int x = 0;
	scanf("%d", &x);
	SL* temp= SListFind(sl,x);
	if (temp == NULL)
		printf("未找到该数据！\n");
	else
	printf("%p\n", temp);*/
	//SListPopFront(&sl);
	//SListPopFront(&sl);
	//SListPopBack(&sl);
	//SListPopBack(&sl);
			SListPrint(sl);
	}
int main() {
	
	test();
	return 0;
}




//#include <stdio.h>
//#include <stdlib.h>
////默认数组长度
//#define LEN 4
//
//int main() {
//	int tmp = 0;
//	int* node = NULL;
//	int** arr = (int**)malloc(LEN * sizeof(int*));
//	if (arr == NULL) exit(1);
//	for (int i = 0; i < LEN; i++) {
//		node = malloc(sizeof(int));
//		if (node == NULL) goto lable;
//		tmp = i; //tmp++
//		*node = i * 100;
//		*(arr + i) = node;
//		node = NULL;
//		printf("%d ", *(*(arr + i)));
//	}
//	printf("\n");
//	for (int i = 0; i < LEN; i++) {
//		free(*(arr + i));
//	}
//	free(arr);
//	exit(0);
//lable:
//	for (int i = 0; i < tmp; i++) {
//		free(*(arr + i));
//	}
//	free(arr);
//	exit(1);
//	return 0;
//}
//int main() {
//	int grid[][3] = { {1,0,2 }, {1, 0, 2}};
//	int gridSize = sizeof(grid) / sizeof(grid[0]);
//	int gridColSize = 3;
//	for (int i = 0; i < gridSize - 1; i++) {
//		for (int j = 0; j < gridColSize; j++) {
//			if (grid[i][j] != grid[i + 1][j]) {
//				printf("fasle");
//				return 1;
//			}
//		}
//	}
//	for (int i = 0; i < gridSize; i++) {
//		for (int j = 0; j < gridColSize - 1; j++) {
//			if (grid[i][j] == grid[i][j + 1]) {
//				printf("fasle");
//				return 1;
//			}
//		}
//	}
//	printf("true");
//	return 0;
//}