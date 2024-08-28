#define _CRT_SECURE_NO_WARNINGS
#include"2024.8.28.h"
//初始化链表第一个
//void SListInit(SL** sl) {
//		(*sl)->date = 0;
//	(*sl)->p = NULL;
//}

//尾插
void SListPushBack(SL** ssl) {
	datetype x = 0;
	printf("请输入你要插入的数据：\n");
	scanf("%d", &x);
	SL* new = (SL*)malloc(sizeof(SL) * 1);
	if (new == NULL) {
		printf("%s\n", strerror(errno));
		exit(1);
	}
	new->date = x;
	new->p = NULL;
	if (*ssl == NULL) {
		*ssl = new;
	}
	else {
		SL* titl = *ssl;
		while (titl->p != NULL) {
			titl = titl->p;
		}
		titl->p = new;
	}
}

//打印测试
void SListPrint(SL* sl) {
	while (sl != NULL) {
		printf("%d->", sl->date);
		sl = sl->p;
	}
}
//头插
void SListPushFront(SL** ssl) {
	datetype x =0;
	printf("请输入要插入的数据：\n");
	scanf("%d", &x);
	SL* new = (SL*)malloc(sizeof(SL));
	if (new == NULL) {
		printf("%s\n", strerror(errno));
		exit(1);
	}
	if (*ssl == NULL) {
		new->date = x;
		new->p = NULL;
		*ssl = new;
	}
	else {
		new->date = x;
		new->p = *ssl;
		*ssl = new;
	}
}

//尾删
void SListPopBack(SL** ssl) {
	assert(*ssl);
	if ((*ssl)->p == NULL) {
		free(*ssl);
		*ssl = NULL;
	}
	else {
		SL* temp = *ssl;
		SL* temp0 = NULL;
		while (temp->p != NULL) {
			temp0 = temp;
			temp = temp->p;
		}
		free(temp);
		temp0->p = NULL;
		temp = NULL;
	}
}
//头删
void SListPopFront(SL** ssl) {
	*ssl = (*ssl)->p;
}
