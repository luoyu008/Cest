#define _CRT_SECURE_NO_WARNINGS
#include"2024.9.4.h"
void test(){
	queue q;
	tree* t = TREECreat();
	int size = TREENum(t);
	QUEUEInit(&q, size);
	if (t == NULL)
		return;
	printf("%c ", t->date);

	QUEUEPush(&q, t);
	while (!QUEUEEmpty(&q)) {
		t = QUEUEPop(&q);
		if (t->Lchild) {
			printf("%c ", t->Lchild->date);
			QUEUEPush(&q, t->Lchild);
		}
		if (t->Rchild) {
			printf("%c ", t->Rchild->date);
			QUEUEPush(&q, t->Rchild);
		}
	}
}

//迭代先序遍历
void TREEFRONT(tree* t) {
	stack* s=NULL;
	if (t == NULL)
		return;
	STACKPush(&s, t,0);
	while (!STACKEmpty(&s)) {
		stack* temp = STACKPop(&s);
		if (temp->t->Rchild) {
			STACKPush(&s, temp->t->Rchild,0);
		}
		if (temp->t->Lchild) {
			STACKPush(&s, temp->t->Lchild,0);
		}
		STACKPush(&s, temp->t, 1);
		stack* cur = s;
		while (cur->next != NULL) {
			cur = cur->next;
		}
		if (cur->x == 1)
		{
			printf("%c ", cur->t->date);
			STACKPop(&s);
		}
	}
}
//迭代中序遍历
void TREEMID(tree* t) {
	stack* s = NULL;
	if (t == NULL)
		return;
	STACKPush(&s, t, 0);
	while (!STACKEmpty(&s)) {
		stack* temp = STACKPop(&s);
		
		if (temp->t->Rchild) {
			STACKPush(&s, temp->t->Rchild, 0);
		}
		STACKPush(&s, temp->t, 1);
		if (temp->t->Lchild) {
			STACKPush(&s, temp->t->Lchild, 0);
		}
		stack* cur = s;
		while (cur->next != NULL) {
			cur = cur->next;
		}
		while (cur->x == 1) {
			printf("%c ", cur->t->date);
			cur = cur->prev;
			STACKPop(&s);
		}
	}
}
int main() {
	//test();
	tree* t = TREECreat();
	//TREEFRONT(t);
	TREEMID(t);
	return 0;
}