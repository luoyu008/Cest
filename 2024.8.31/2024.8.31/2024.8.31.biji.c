#define _CRT_SECURE_NO_WARNINGS
#include"2024.8.31.h"
//初始化
list* ListInit() {
	list* new = (list*)malloc(sizeof(list));
	new->next = new;
	new->prev = new;
	new->val = NULL;
	return new;
}
//尾插
void ListPushBack(list* plist) {
	assert(plist);
	datetype x = 0;
	printf("请输入你要插入的数据：\n");
	scanf("%d", &x);
	list* tail = (list*)malloc(sizeof(list));
	tail = plist->prev;
	list* new = (list*)malloc(sizeof(list));
	new->val = x;
	tail->next = new;
	new->prev = tail;
	plist->prev = new;
	new->next = plist;
	
}
//打印 
void ListPrint(list* plist) {
	assert(plist);
	list* temp = plist->next;
	while (temp != plist) {
		printf("%d ", temp->val);
		temp = temp->next;
	}
	printf("\n");
}
//尾删
void ListPopBack(list* plist) {
	assert(plist);
	assert(plist->next != plist);			
	list* tail = plist->prev->prev;
	list* no = plist->prev;
	tail->next = plist;
	plist->prev = tail;
	free(no);
	no = NULL;
}
//头插
void ListPushFront(list* plist) {
	assert(plist);
	datetype x = 0;
	printf("请输入你要插入的数据：\n");
	scanf("%d", &x);
	list* new = (list*)malloc(sizeof(list));
	new->val = x;
	new->next = plist->next;
	plist->next->prev = new;
	plist->next = new;
	new->prev = plist;
}
//头删
void ListPopFront(list* plist) {
	assert(plist);
	assert(plist->next != plist);
	list* cur = plist->next;
	cur->next->prev = cur->prev;
	plist->next = cur->next;
	free(cur);
	cur = NULL;
}

//查找
list* ListFind(list* plist,datetype x) {
	assert(plist);
	list* temp = plist->next;
	while (temp != plist) {
		if (temp->val == x) {
			return temp;
		}
		else
			temp = temp->next;
	}
	return NULL;
}
//某位前插入
void ListInsertF(list* plist) {
	assert(plist);
	datetype x = 0;
	printf("请输入你要插入的位置的下一个位置的元素：\n");
	scanf("%d", &x);
	datetype date = 0;
	printf("请输入你要插入的数据：\n");
	scanf("%d", &date);
	list* cur = ListFind(plist,x);
	list* new = (list*)malloc(sizeof(list));
	new->val = date;
	new->prev = cur->prev;
	cur->prev->next = new;
	cur->prev = new;
	new->next = cur;
}
//某位后插入
void ListInsertB(list* plist) {
	assert(plist);
	datetype x = 0;
	printf("请输入你要插入的位置的前一个位置的元素：\n");
	scanf("%d", &x);
	datetype date = 0;
	printf("请输入你要插入的数据：\n");
	scanf("%d", &date);
	list* cur = ListFind(plist, x);
	list* new = (list*)malloc(sizeof(list));
	new->val = date;
	new->next = cur->next;
	cur->next->prev = new;
	cur->next = new;
	new->prev = cur;
}
//删除某位
void ListEarse(list* plist) {
	assert(plist);
	datetype x = 0;
	printf("请输入你要删除的元素：\n");
	scanf("%d", &x);
	list* cur = ListFind(plist, x);
	cur->prev->next = cur->next;
	cur->next->prev = cur->prev;
	free(cur);
	cur = NULL;
}