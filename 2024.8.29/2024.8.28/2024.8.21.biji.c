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
	assert(*ssl);
	if ((*ssl)->p == NULL) {
		free(*ssl);
		*ssl = NULL;
	}
	else {
		SL* next = (*ssl)->p;
		free(*ssl);
		*ssl = next;
	}
}
//查找数据
SL* SListFind(SL* sl, datetype x) {
	assert(sl);
	while (sl != NULL) {
		if (sl->date == x)
			break;
		else
			sl = sl->p;
		
	}
	return sl;
	}

//在数据位置之前插入数据
void SListInsertF(SL** ssl) {
	if (*ssl == NULL) {
		SListPushFront(ssl);
	}
	else {
		printf("请输入你要插入的位置的数据：\n");
		datetype x = 0;
		scanf("%d", &x);
		printf("请输入你要插入的数据：\n");
		int date = 0;
		scanf("%d", &date);
		SL* temp = SListFind(*ssl, x);
		SL* new = (SL*)malloc(sizeof(SL));
		if (temp == *ssl) {
			new->date = date;
			new->p = *ssl;
			*ssl = new;
		}
		else {
		new->date = date;
		SL* count = *ssl;
			while (count->p != NULL) {
				if ((count->p)->date == x)
					break;
				else
					count = (count)->p;
			}
			(count)->p = new;
			new->p = temp;
		}
	}
}

;//在数据位置后插入数据
void SListInsertB(SL** ssl) {
	if (*ssl == NULL) {
		SListPushBack(ssl);
	}
	else {
		datetype x = 0;
		printf("请输入你要插入的数据的位置：\n");
		int n = 0;
		scanf("%d", &n);
		printf("请输入你要插入的数据：\n");
		scanf("%d", &x);
		SL* temp =SListFind(*ssl,n);
		SL* new = (SL*)malloc(sizeof(SL));
		SL* tempnext = *ssl;
		while (tempnext != NULL) {
			if ((temp->p) == tempnext)
				break;
			else
				tempnext = tempnext->p;
		}
		new->date = x;
		temp->p = new;
		new->p = tempnext;

	}
}

//删除某位
void SListErase(SL** ssl) {
	datetype x = 0;
	printf("请输入要删除的数据：\n");
	scanf("%d", &x);
	if ((*ssl)->date == x) {
		SListPopFront(ssl);
	}
	else {
		SL* count = SListFind(*ssl, x);
		SL* temp =*ssl;
		while (temp->p->date!=count) {
			temp = temp->p;
		}
		temp->p = temp->p->p;
		free(count);
	}
}
//删除某位的后一位
void SListEraseF(SL** ssl) {
	datetype x = 0;
	printf("请输入要删的前一个数据：\n");
	scanf("%d", &x);
	SL* temp = *ssl;
	while (temp->date != x) {
		temp = temp->p;
	}
	SL* count = temp->p;
	temp->p = temp->p->p;
	free(count);
}
//销毁链表
void SListdestory(SL** ssl) {
	SL* temp = *ssl;
	while (*ssl != NULL) {
		temp = *ssl;
		*ssl = (*ssl)->p;
		free(temp);
	}
}
