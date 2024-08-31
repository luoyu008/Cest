#define _CRT_SECURE_NO_WARNINGS
#include"2024.8.31.h"
//��ʼ��
list* ListInit() {
	list* new = (list*)malloc(sizeof(list));
	new->next = new;
	new->prev = new;
	new->val = NULL;
	return new;
}
//β��
void ListPushBack(list* plist) {
	assert(plist);
	datetype x = 0;
	printf("��������Ҫ��������ݣ�\n");
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
//��ӡ 
void ListPrint(list* plist) {
	assert(plist);
	list* temp = plist->next;
	while (temp != plist) {
		printf("%d ", temp->val);
		temp = temp->next;
	}
	printf("\n");
}
//βɾ
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
//ͷ��
void ListPushFront(list* plist) {
	assert(plist);
	datetype x = 0;
	printf("��������Ҫ��������ݣ�\n");
	scanf("%d", &x);
	list* new = (list*)malloc(sizeof(list));
	new->val = x;
	new->next = plist->next;
	plist->next->prev = new;
	plist->next = new;
	new->prev = plist;
}
//ͷɾ
void ListPopFront(list* plist) {
	assert(plist);
	assert(plist->next != plist);
	list* cur = plist->next;
	cur->next->prev = cur->prev;
	plist->next = cur->next;
	free(cur);
	cur = NULL;
}

//����
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
//ĳλǰ����
void ListInsertF(list* plist) {
	assert(plist);
	datetype x = 0;
	printf("��������Ҫ�����λ�õ���һ��λ�õ�Ԫ�أ�\n");
	scanf("%d", &x);
	datetype date = 0;
	printf("��������Ҫ��������ݣ�\n");
	scanf("%d", &date);
	list* cur = ListFind(plist,x);
	list* new = (list*)malloc(sizeof(list));
	new->val = date;
	new->prev = cur->prev;
	cur->prev->next = new;
	cur->prev = new;
	new->next = cur;
}
//ĳλ�����
void ListInsertB(list* plist) {
	assert(plist);
	datetype x = 0;
	printf("��������Ҫ�����λ�õ�ǰһ��λ�õ�Ԫ�أ�\n");
	scanf("%d", &x);
	datetype date = 0;
	printf("��������Ҫ��������ݣ�\n");
	scanf("%d", &date);
	list* cur = ListFind(plist, x);
	list* new = (list*)malloc(sizeof(list));
	new->val = date;
	new->next = cur->next;
	cur->next->prev = new;
	cur->next = new;
	new->prev = cur;
}
//ɾ��ĳλ
void ListEarse(list* plist) {
	assert(plist);
	datetype x = 0;
	printf("��������Ҫɾ����Ԫ�أ�\n");
	scanf("%d", &x);
	list* cur = ListFind(plist, x);
	cur->prev->next = cur->next;
	cur->next->prev = cur->prev;
	free(cur);
	cur = NULL;
}