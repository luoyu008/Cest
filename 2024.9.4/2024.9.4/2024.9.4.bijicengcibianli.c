#define _CRT_SECURE_NO_WARNINGS
#include"2024.9.4.h"
tree* TREECreat() {
	char date;
	scanf("%c", &date);
	if (date == '#')
		return NULL;
	tree* t = (tree*)malloc(sizeof(tree));
	t->date = date;
	t->Lchild = TREECreat();
	t->Rchild = TREECreat();
	return t;
}
//ͳ�ƽڵ����
int TREENum(tree* root) {
	static int count = 0;
	if (root == NULL)
		return 0;
	count++;
	TREENum(root->Lchild);
	TREENum(root->Rchild);
	return count;
}
//���г�ʼ��
void QUEUEInit(queue* qq, int size) {
	qq->arr = (tree**)malloc(sizeof(tree*) * size);
	qq->front = 0;
	qq->tail = 0;
}

//���
void QUEUEPush(queue* qq,tree* t) {
	qq->arr[qq->tail] = t;
	qq->tail++;
}
//����
tree* QUEUEPop(queue*qq) {
	tree* temp = qq->arr[qq->front];
	for (int i = 1; i < qq->tail;i++) {
		qq->arr[i - 1] = qq->arr[i];
	}
	qq->tail = qq->tail - 1;
	return temp;
}
//�����п�
int QUEUEEmpty(queue* qq) {
	return qq->front == qq->tail;
}


//��ջ
void STACKPush(stack** ss,tree* pt,int x) {
	if (pt == NULL)
		return;
	if (*ss == NULL) {
		stack* new = (stack*)malloc(sizeof(stack));
		new->x = x;
		new->t = pt;
		new->next = NULL;
		new->prev = NULL;
		*ss = new;
	}
	else {
		stack* cur = *ss;
		while (cur->next != NULL) {
			cur = cur->next;
		}
		stack* new = (stack*)malloc(sizeof(stack));
		new->x = x;
		new->t = pt;
		new->next = NULL;
		new->prev = cur;
		cur->next = new;
	}
}
//ջ�п�
bool STACKEmpty(stack** ss) {
	return *ss == NULL;
}
 //��ջ
tree* STACKPop(stack** ss) {
	if ((*ss)->next == NULL) {
		stack* temp = *ss;
		*ss = NULL;
		return temp;
	}
	stack* cur = *ss;
	stack* prev = NULL;
	while (cur->next != NULL) {
		prev = cur;
		cur = cur->next;
	}
	prev->next = NULL;
	return cur;
}
