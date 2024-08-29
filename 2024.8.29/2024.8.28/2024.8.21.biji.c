#define _CRT_SECURE_NO_WARNINGS
#include"2024.8.28.h"
//��ʼ�������һ��
//void SListInit(SL** sl) {
//		(*sl)->date = 0;
//	(*sl)->p = NULL;
//}

//β��
void SListPushBack(SL** ssl) {
	datetype x = 0;
	printf("��������Ҫ��������ݣ�\n");
	scanf("%d", &x);
	SL* new = (SL*)malloc(sizeof(SL) * 1);
	if (new == NULL) {
		printf("%s\n", strerror(errno));
		exit(1);
	}
	new->date = x;
	new->p = NULL;
	if (*ssl == NULL) {
		*ssl = new;
	}
	else {
		SL* titl = *ssl;
		while (titl->p != NULL) {
			titl = titl->p;
		}
		titl->p = new;
	}
}

//��ӡ����
void SListPrint(SL* sl) {
	while (sl != NULL) {
		printf("%d->", sl->date);
		sl = sl->p;
	}
}
//ͷ��
void SListPushFront(SL** ssl) {
	datetype x =0;
	printf("������Ҫ��������ݣ�\n");
	scanf("%d", &x);
	SL* new = (SL*)malloc(sizeof(SL));
	if (new == NULL) {
		printf("%s\n", strerror(errno));
		exit(1);
	}
	if (*ssl == NULL) {
		new->date = x;
		new->p = NULL;
		*ssl = new;
	}
	else {
		new->date = x;
		new->p = *ssl;
		*ssl = new;
	}
}

//βɾ
void SListPopBack(SL** ssl) {
	assert(*ssl);
	if ((*ssl)->p == NULL) {
		free(*ssl);
		*ssl = NULL;
	}
	else {
		SL* temp = *ssl;
		SL* temp0 = NULL;
		while (temp->p != NULL) {
			temp0 = temp;
			temp = temp->p;
		}
		free(temp);
		temp0->p = NULL;
		temp = NULL;
	}
}
//ͷɾ
void SListPopFront(SL** ssl) {
	assert(*ssl);
	if ((*ssl)->p == NULL) {
		free(*ssl);
		*ssl = NULL;
	}
	else {
		SL* next = (*ssl)->p;
		free(*ssl);
		*ssl = next;
	}
}
//��������
SL* SListFind(SL* sl, datetype x) {
	assert(sl);
	while (sl != NULL) {
		if (sl->date == x)
			break;
		else
			sl = sl->p;
		
	}
	return sl;
	}

//������λ��֮ǰ��������
void SListInsertF(SL** ssl) {
	if (*ssl == NULL) {
		SListPushFront(ssl);
	}
	else {
		printf("��������Ҫ�����λ�õ����ݣ�\n");
		datetype x = 0;
		scanf("%d", &x);
		printf("��������Ҫ��������ݣ�\n");
		int date = 0;
		scanf("%d", &date);
		SL* temp = SListFind(*ssl, x);
		SL* new = (SL*)malloc(sizeof(SL));
		if (temp == *ssl) {
			new->date = date;
			new->p = *ssl;
			*ssl = new;
		}
		else {
		new->date = date;
		SL* count = *ssl;
			while (count->p != NULL) {
				if ((count->p)->date == x)
					break;
				else
					count = (count)->p;
			}
			(count)->p = new;
			new->p = temp;
		}
	}
}

;//������λ�ú��������
void SListInsertB(SL** ssl) {
	if (*ssl == NULL) {
		SListPushBack(ssl);
	}
	else {
		datetype x = 0;
		printf("��������Ҫ��������ݵ�λ�ã�\n");
		int n = 0;
		scanf("%d", &n);
		printf("��������Ҫ��������ݣ�\n");
		scanf("%d", &x);
		SL* temp =SListFind(*ssl,n);
		SL* new = (SL*)malloc(sizeof(SL));
		SL* tempnext = *ssl;
		while (tempnext != NULL) {
			if ((temp->p) == tempnext)
				break;
			else
				tempnext = tempnext->p;
		}
		new->date = x;
		temp->p = new;
		new->p = tempnext;

	}
}

//ɾ��ĳλ
void SListErase(SL** ssl) {
	datetype x = 0;
	printf("������Ҫɾ�������ݣ�\n");
	scanf("%d", &x);
	if ((*ssl)->date == x) {
		SListPopFront(ssl);
	}
	else {
		SL* count = SListFind(*ssl, x);
		SL* temp =*ssl;
		while (temp->p->date!=count) {
			temp = temp->p;
		}
		temp->p = temp->p->p;
		free(count);
	}
}
//ɾ��ĳλ�ĺ�һλ
void SListEraseF(SL** ssl) {
	datetype x = 0;
	printf("������Ҫɾ��ǰһ�����ݣ�\n");
	scanf("%d", &x);
	SL* temp = *ssl;
	while (temp->date != x) {
		temp = temp->p;
	}
	SL* count = temp->p;
	temp->p = temp->p->p;
	free(count);
}
//��������
void SListdestory(SL** ssl) {
	SL* temp = *ssl;
	while (*ssl != NULL) {
		temp = *ssl;
		*ssl = (*ssl)->p;
		free(temp);
	}
}
