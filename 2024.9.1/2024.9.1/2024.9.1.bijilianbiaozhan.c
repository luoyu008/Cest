#define _CRT_SECURE_NO_WARNINGS
#include"2024.9.1.liianbiaozhan.h"
//初始化
//void SLStackInt(slstack* ssl) {
//	
//}
////栈判空
//bool SLStackEmpty(slstack* ssl) {
//	if (ssl == NULL)
//		return true;
//	return false;
//}
////入栈
//void SLStackPush(slstack** ssl) {
//	datetype x = 0;
//	printf("请输入你要入栈的数据:\n");
//	scanf("%d", &x);
//	slstack* new = (slstack*)malloc(sizeof(slstack));
//	new->val = x;
//	bool judge = SLStackEmpty(*ssl);
//	if (judge) {
//		new->next = NULL;
//		*ssl = new;
//	}
//	else
//	{
//		new->next = *ssl;
//		*ssl = new;
//	}
//}
////出栈
//void SLStackPop(slstack** ssl) {
//	bool judge = SLStackEmpty(*ssl);
//	if (judge) {
//		printf("栈为空无法出栈\n");
//		return;
//	}
//	else {
//		printf("栈顶数据为：%d\n", (*ssl)->val);
//		*ssl = (*ssl)->next;
//	}
//}
////取栈顶数据
//void SLStackTop(slstack** ssl) {
//	bool judge = SLStackEmpty(*ssl);
//	if (judge) {
//		printf("栈为空无法取栈顶数据\n");
//		return;
//	}
//	else {
//		printf("栈顶数据为：%d\n", (*ssl)->val);
//	}
//}
//
////打印
//void SLStackPrint(slstack **ssl) {
//	bool judge = SLStackEmpty(*ssl);
//	if (judge) {
//		printf("栈为空无法打印\n");
//		return;
//	}
//	else {
//		printf("注意此为倒序\n");
//		slstack* cur = *ssl;
//		while (cur != NULL) {
//			printf("%d ", cur->val);
//			cur = cur->next;
//		}
//		printf("\n");
//	}
//}
////销毁栈
//void SLStackDestroy(slstack** ssl) {
//	bool judge = SLStackEmpty(*ssl);
//	if (judge) {
//		printf("栈为空无法销毁\n");
//		return;
//	}
//	else {
//		while (*ssl != NULL) {
//			slstack* now = *ssl;
//			*ssl = (*ssl)->next;
//			free(now);
//			now = NULL;
//		}
//	}
//}
////栈数据量
//int SLStackSize(slstack** ssl) {
//	int count = 0;
//	bool judge = SLStackEmpty(*ssl);
//	if (judge) {
//		return -1;
//	}
//	else {
//		while (*ssl != NULL) {
//			count++;
//			*ssl = (*ssl)->next;
//		}
//		return count;
//	}
//}