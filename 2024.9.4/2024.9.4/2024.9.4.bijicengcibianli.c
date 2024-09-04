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
//统计节点个数
int TREENum(tree* root) {
	static int count = 0;
	if (root == NULL)
		return 0;
	count++;
	TREENum(root->Lchild);
	TREENum(root->Rchild);
	return count;
}
//队列初始化
void QUEUEInit(queue* qq, int size) {
	qq->arr = (tree**)malloc(sizeof(tree*) * size);
	qq->front = 0;
	qq->tail = 0;
}

//入队
void QUEUEPush(queue* qq,tree* t) {
	qq->arr[qq->tail] = t;
	qq->tail++;
}
//出队
tree* QUEUEPop(queue*qq) {
	tree* temp = qq->arr[qq->front];
	for (int i = 1; i < qq->tail;i++) {
		qq->arr[i - 1] = qq->arr[i];
	}
	qq->tail = qq->tail - 1;
	return temp;
}
//队列判空
int QUEUEEmpty(queue* qq) {
	return qq->front == qq->tail;
}


//入栈
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
//栈判空
bool STACKEmpty(stack** ss) {
	return *ss == NULL;
}
 //出栈
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
