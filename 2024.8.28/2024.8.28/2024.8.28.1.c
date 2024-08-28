#define _CRT_SECURE_NO_WARNINGS
#include"2024.8.28.h"
void test() {
	SL* sl=NULL;
	//SListInit(&sl);
	/*SListPushBack(&sl);
	SListPushBack(&sl);
	SListPushBack(&sl);
	SListPushBack(&sl);*/
	//SListPushBack(&sl);
	SListPushBack(&sl);
	//SListPushFront(&sl);
	//SListPushBack(&sl);
	//SListPopFront(&sl);
	SListPopBack(&sl);
	SListPopBack(&sl);
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