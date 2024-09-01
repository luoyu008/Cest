#define _CRT_SECURE_NO_WARNINGS
#include"2024.9.1.lianbiaoduilie.h"
//��ʼ��
void QUEUEInit(q* pp) {
	assert(pp);
	pp->head = NULL;
	pp->tail = NULL;
}
//�п�
bool QUEUQEmpty(q* pp) {
	assert(pp);
	if (pp->head == NULL)
		return true;
	return false;
}
//���
void QUEUEPush(q* pp) {
	assert(pp);
	datetype x = 0;
	printf("��������Ҫ��ӵ����ݣ�\n");
	scanf("%d", &x);
	bool judge = QUEUQEmpty(pp);
	if (judge) {
		queue* new = (queue*)malloc(sizeof(queue));
		new->val = x;
		pp->head = new;
		pp->head->next = NULL;
		pp->tail = new;
	}
	else {
		queue* new = (queue*)malloc(sizeof(queue));
		queue* cur = pp->head;
		new->val = x;
		new->next = cur;
		pp->head = new;
	}
}
//����
void QUEUEPop(q* pp) {
	assert(pp);
	bool judge = QUEUQEmpty(pp);
	if (judge) {
		printf("��Ϊ���޷�����\n");
		return;
	}
	else {
		if (pp->head == pp->tail) {
			printf("�������ݣ�%d\n", pp->tail->val);
			free(pp->head);
			pp->head = NULL;
			pp->tail = NULL;
		}
		else {
			queue* now = pp->head;
			queue* tailprev = NULL;
			while (now != NULL)
			{
				if (now->next == pp->tail) {
					tailprev = now;
					break;
				}
				now = now->next;
			}
			printf("�������ݣ�%d\n", pp->tail->val);
			queue* temp = pp->tail;
			pp->tail = tailprev;
			pp->tail->next = NULL;
			free(temp);
			temp = NULL;
		}
	}
}
//����
void QUEUEDestroy(q* pp) {
	assert(pp);
	bool judge = QUEUQEmpty(pp);
	if (judge) {
		printf("��Ϊ���޷�����\n");
		return;
	}
	else {
		while (pp->head != NULL) {
			if (pp->head == pp->tail) {
				free(pp->head);
				pp->head = NULL;
				pp->tail = NULL;
				break;
			}
				queue* now = pp->head;
			pp->head = pp->head->next;
			free(now);
			now = NULL;
		}
	}
}
//��ͷ����
datetype QUEUEFront(q* pp) {
	assert(pp);
	bool judge = QUEUQEmpty(pp);
	if (judge) {
		return -1;
	}
	else {
		datetype x = 0;
		x = pp->tail->val;
		return x;
	}
}
//��β����
datetype QUEUEBack(q* pp) {
	assert(pp);
	bool judge = QUEUQEmpty(pp);
	if (judge) {
		return -1;
	}
	else {
		datetype x = 0;
		x = pp->head->val;
		return x;
	}
}
//��������
int QUEUESize(q* pp) {
	assert(pp);
	bool judge = QUEUQEmpty(pp);
	if (judge) {
		return -1;
	}
	else {
		datetype x = 0;
		queue* cur = pp->head;
		while (cur != NULL) {
			x++;
			cur = cur->next;
		}
		return x;
	}
}
