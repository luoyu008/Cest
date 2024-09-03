#define _CRT_SECURE_NO_WARNINGS
#include"2024.9.3.h"
////树创建
//tree* TREECreat(char date) {
//	tree* t = (tree*)malloc(sizeof(tree));
//	t->date = date;
//	t->Lchild = NULL;
//	t->Rchild = NULL;
//	return t;
//}
// 
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
//树连接
void TREELink(tree* t, struct TREE* Lchild, struct TREE* Rchild) {
	t->Lchild = Lchild;
	t->Rchild = Rchild;
}
//打印
void PRINT(tree* root)
{
	printf("%c ", root->date);
}
//先序
void FRONT(tree* root)
{
	if (root) {
		PRINT(root);
		FRONT(root->Lchild);
		FRONT(root->Rchild);
	}
}
//先序非递归
void FRONTF(tree* root) {
	stack* s =(stack*) malloc(sizeof(stack));
	if (root) {
		while (s != NULL) {
			
		}
	}
}

;//中序
void MITREE(tree* root) {
	if (root) {
		MITREE(root->Lchild);
		PRINT(root);
		MITREE(root->Rchild);
	}
}
;//后序
void LAST(tree* root) {
	if (root) {
		LAST(root->Lchild);
		LAST(root->Rchild);
		PRINT(root);
	}
}