#define _CRT_SECURE_NO_WARNINGS
#include"2024.9.1.liianbiaozhan.h"
//��ʼ��
//void SLStackInt(slstack* ssl) {
//	
//}
////ջ�п�
//bool SLStackEmpty(slstack* ssl) {
//	if (ssl == NULL)
//		return true;
//	return false;
//}
////��ջ
//void SLStackPush(slstack** ssl) {
//	datetype x = 0;
//	printf("��������Ҫ��ջ������:\n");
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
////��ջ
//void SLStackPop(slstack** ssl) {
//	bool judge = SLStackEmpty(*ssl);
//	if (judge) {
//		printf("ջΪ���޷���ջ\n");
//		return;
//	}
//	else {
//		printf("ջ������Ϊ��%d\n", (*ssl)->val);
//		*ssl = (*ssl)->next;
//	}
//}
////ȡջ������
//void SLStackTop(slstack** ssl) {
//	bool judge = SLStackEmpty(*ssl);
//	if (judge) {
//		printf("ջΪ���޷�ȡջ������\n");
//		return;
//	}
//	else {
//		printf("ջ������Ϊ��%d\n", (*ssl)->val);
//	}
//}
//
////��ӡ
//void SLStackPrint(slstack **ssl) {
//	bool judge = SLStackEmpty(*ssl);
//	if (judge) {
//		printf("ջΪ���޷���ӡ\n");
//		return;
//	}
//	else {
//		printf("ע���Ϊ����\n");
//		slstack* cur = *ssl;
//		while (cur != NULL) {
//			printf("%d ", cur->val);
//			cur = cur->next;
//		}
//		printf("\n");
//	}
//}
////����ջ
//void SLStackDestroy(slstack** ssl) {
//	bool judge = SLStackEmpty(*ssl);
//	if (judge) {
//		printf("ջΪ���޷�����\n");
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
////ջ������
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