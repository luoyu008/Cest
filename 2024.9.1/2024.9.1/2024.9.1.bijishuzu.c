#define _CRT_SECURE_NO_WARNINGS
#include"2024.9.1shuzu.h"
//��ʼ��
void StackInit(stack* s) {
	assert(s);
	s->a =NULL;
	s->capacity = 0;
	s->top = -1;
}
//ջ�п�
bool StackEmpty(stack* s) {
	if (s->a == NULL) {
		return true;
	}
	return false;
}
//����
stack* StackExpansion(stack* s) {
	datetype* new = (datetype*)realloc(s->a, sizeof(datetype)*s->capacity*2);
	s->capacity = s->capacity * 2;
	return new;
}

//��ջ
void StackPush(stack* s) {
	datetype x = 0;
	printf("��������Ҫ��ջ�����ݣ�\n");
	scanf("%d", &x);
	s->top++;
	bool judge = StackEmpty(s);
	if (judge) {
		datetype * now = (datetype*)malloc(sizeof(datetype) * 5);
		if (now == NULL) {
			printf("malloc fail");
			exit(1);
		}
		else
			s->a = now;
		s->capacity = 5;
	}
	if (s->top == s->capacity) {
	    datetype* new=StackExpansion(s);
		if (new == NULL) {
			printf("realloc fail\n");
			exit(1);
		}
		else {
			s->a = new;
		}
	}
	s->a[s->top] = x;
}
//��ջ
void StackPop(stack* s){
	bool judge = StackEmpty(s);
	if (judge) {
		printf("ջΪ��\n");
		exit(1);
	}
	else {
		if (s->top == -1) {
			printf("ջΪ��\n");
			exit(1);
		}
		else {
			s->top--;
		}
	}
}
//ȡջ������
datetype StackTop(stack* s) {
	assert(s);
	bool judge = StackEmpty(s);
	if (judge) {
		return -1;
	}
	else {
		if (s->top == -1) {
			return -1;
		}
		else {
			return s->a[s->top];
		}
	}
}

//��ӡ
void StackPrint(stack* s) {
	bool judge = StackEmpty(s);
	if (judge)
	{
		printf("ջΪ��\n");
		return;
	}
	else {
		if (s->top == -1) {
			printf("ջΪ��\n");
			return;
		}
		else {
			for (int i = 0; i <= s->top; i++) {
				printf("%d ", s->a[i]);
			}
			printf("\n");
		}
	}
}
//����ջ
void StackDestroy(stack* s) {
	assert(s);
	free(s->a);
	s->a = NULL;
	s->capacity = 0;
	s->top = -1;
}
//ջ������
int StackSize(stack* s) {
	bool judge = StackEmpty(s);
	if (judge) {
		return -1;
	}
	else {
		if (s->top == -1) {
			return -1;
		}
		else {
			return s->top+1;
		}
	}
}
