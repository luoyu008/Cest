#define _CRT_SECURE_NO_WARNINGS
#include"2024.8.273.h"
//�ݹ��㷨ʱ�临�Ӷȴ����������ݹ����*ÿ�εݹ���õĴ���

//�ռ临�Ӷȼ�����ǳ�������ʱ�Ķ���ռ�ÿռ�ı������� Ҳ����ʹ�ô�O������

//˳����������  ����������Ļ�����Ҫ�������Ǵ�ͷ��ʼ�����洢�Ĳ��ܼ����Ծ

//��ʼ��
void SeqlistInit(s* s1) {
	s1->a = NULL;
	s1->size = 0;
	s1->capactity = 0;
}
////��ʼ���ٿռ�
//void Seqlistm(s* s1) {
//	s1->a =(SLdatetype*) malloc(sizeof(SLdatetype) * 2);
//	s1->capactity = 2;
//}
//����
void Seqlistmm(s* s1) {
	int new = s1->capactity * 2;
	SLdatetype * l = (SLdatetype*)realloc(s1->a,(new==0?4:new)*sizeof(SLdatetype));
	if (l == NULL) {
		printf("%s\n", strerror(errno));
		return;
	}
	else
		s1->a = l;
	if (new == 0) {
		s1->capactity = 4;
	}else
	s1->capactity *= 2;
}
//��β����
void SeqlistPushBack(s* s1) {
	SLdatetype x = 0;
		printf("������Ҫ�����ֵ��\n");
	scanf("%d", &x);
	if (s1->size == s1->capactity) {
		Seqlistmm(s1);
	}
	
	s1->a[s1->size] = x;
	s1->size += 1;
}
//���ٱ�
void Seqlistdestory(s* s1) {
	free(s1->a);
	s1->a = NULL;
}
//��βɾ��
void SeqlistPopBack(s* s1) {
	/*if (s1->size != 0) {
		s1->size--;
	}*/
	assert(s1->size > 0);
	s1->size--;
}

;//��ͷ����
void SeqlistPushFront(s* s1) {
	SLdatetype x = 0;
	printf("������Ҫ�����ֵ��\n");
	scanf("%d", &x);
	s1->size++;
	if (s1->capactity == s1->size) {
		Seqlistmm(s1);
	}
	for (int i = s1->size-1; i >=1; i--) {
		s1->a[i] = s1->a[i - 1];
	}
	s1->a[0] = x;
}

;//��ͷɾ��
void SeqlistPopFront(s* s1) {
	//assert(s1->size > 0);
	if (s1->size > 0) {
		for (int i = 0; i < s1->size; i++) {
			s1->a[i] = s1->a[i + 1];
		}
		s1->size--;
	}
}

;//��ӡ����
void SeqlistPrintf(s* s1) {
	for (int i = 0; i < s1->size; i++) {
		printf("%d ", s1->a[i]);
	}
	printf("\n");
}
//�ҵ�x��λ�ò�����
void SeqlistFind(s* s1) {
	SLdatetype x = 0;
	printf("������Ҫ���ҵ�ֵ��\n");
	scanf("%d", &x);
	int i = 0;
	for ( i = 0; i < s1->size; i++) {
		if (s1->a[i] == x) {
			printf("�����ݵ�λ���ǣ�%d\n", i + 1);
			break;
		}
	}
	if (i == s1->size)
		printf("δ�ҵ������ݣ�\n");

}
//ɾ��xλ�õ�����
void SeqlistPopn(s* s1) {
	int n = 0;
	printf("��������Ҫɾ����λ�ã�\n");
	scanf("%d", &n);
	if (n <= s1->size&&n>0) {
		for (int i = n - 1; i < s1->size - 1; i++) {
			s1->a[i] = s1->a[i + 1];
		}
		s1->size--;
	}
	else
		printf("λ����Ч��\n");
}

//����nλ��һ������
void SeqlistPushn(s* s1) {
	SLdatetype x = 0;
	int n = 0;
	printf("��������Ҫ�����λ�ã�\n");
	scanf("%d", &n);
	printf("��������Ҫ��������ݣ�\n");
	scanf("%d", &x);
	if (n > 0 && n <= s1->size+1) {
		
		s1->size++;
		if (s1->size == s1->capactity) {
			Seqlistmm(s1);
		}
		if (n == s1->size + 1) {
			s1->a[s1->size-1] = x;
		}else
		for (int i = s1->size-1; i >=n-1; i--) {
			s1->a[i] = s1->a[i -1];
		}
		s1->a[n - 1] = x;
	}
	else
		printf("λ����Ч��\n");
}