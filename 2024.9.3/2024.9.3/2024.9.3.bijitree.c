#define _CRT_SECURE_NO_WARNINGS
#include"2024.9.3.h"
////������
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
//������
void TREELink(tree* t, struct TREE* Lchild, struct TREE* Rchild) {
	t->Lchild = Lchild;
	t->Rchild = Rchild;
}
//��ӡ
void PRINT(tree* root)
{
	printf("%c ", root->date);
}
//����
void FRONT(tree* root)
{
	if (root) {
		PRINT(root);
		FRONT(root->Lchild);
		FRONT(root->Rchild);
	}
}
//����ǵݹ�
void FRONTF(tree* root) {
	stack* s =(stack*) malloc(sizeof(stack));
	if (root) {
		while (s != NULL) {
			
		}
	}
}

;//����
void MITREE(tree* root) {
	if (root) {
		MITREE(root->Lchild);
		PRINT(root);
		MITREE(root->Rchild);
	}
}
;//����
void LAST(tree* root) {
	if (root) {
		LAST(root->Lchild);
		LAST(root->Rchild);
		PRINT(root);
	}
}