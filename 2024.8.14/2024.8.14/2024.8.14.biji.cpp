#define _CRT_SECURE_NO_WARNINGS
#include"2024.8.14.h"
//��̬�ڴ����
//malloc����
//void* malloc(size_t size);
//����size��С���ֽڵ��ڴ�ռ� ���ؿ��ٵĿռ����ʼ��ַ   ������ʧ��ʱ����NULL��ָ��
//free���� ֻ���ͷŶ�̬�ڴ濪�ٵĿռ� free��p����֮��һ��Ҫp=NULL����Ϊ��ָ��
//void free(void* ptr);
//int main() {
//	int a[10];//�ռ���ջ��
//	int* p = (int *)malloc(INT_MAX*2);//�ռ��ڶ���
//	int* pp = (int*)malloc(sizeof(int) * 10);
//	if (p == NULL) {
//		printf("%s", strerror(errno));
//		return 1;
//	}
//	free(p);
//	p = NULL;
//	return 0;//���˳�ʱϵͳ���Զ����տռ�
//}

//calloc���� �ڴ濪�ٵ�ͬʱ��ʼ��Ϊ0 ���ؿ��ٵ���ʼ��ַ
//void* calloc(size_t num, size_t size);
//num��Ҫ���ٵ�Ԫ�ظ���  size��һ��Ԫ�صĴ�С
//int main() {
//	int a[10];//�ռ���ջ��
//	int* p = (int *)calloc(10,sizeof(int));//�ռ��ڶ���
//	if (p == NULL) {
//		printf("%s", strerror(errno));
//		return 1;
//	}
//	free(p);
//	p = NULL;
//	return 0;//���˳�ʱϵͳ���Զ����տռ�
//}

//realloc���� �ڴ��������
//void* realloc(void* ptr, size_t size);
//ptr����Ҫ�������ڴ����ʼ��ַ  size����Ҫ�������ڴ���´�С  �����µ��ڴ�ռ����ʼ��ַ
//�˺�����Ϊ������� ��pΪ40�ֽ�  �����Ϊ80�ֽ�
//��һ�֣���p���ռ����40���ֽ�����������ռ�� �򿪱��µĴ�СΪ80���ֽڵĿռ� Ȼ���p������ݿ������µĿռ�ptr��
//���ͷŵ�p�ռ� ����ptr����ʼ��ַ
//�ڶ��֣���p���ռ����40���ֽ�û����������ռ�� ��ֱ�ӽ�p���ռ������չ40���ֽ� �������ռ����ʼ��ַ
//realloc(NULL,40)==malloc(40);
//int main() {
//	int a[10];//�ռ���ջ��
//	int* p = (int *)calloc(10,sizeof(int));//�ռ��ڶ���
//	if (p == NULL) {
//		printf("%s", strerror(errno));
//		return 1;
//	}
//	for (int i = 0; i < 10; i++) {
//		*(p + i) = i + 1;
//	}
//	int* pp = (int*)realloc(p, sizeof(int) * 20);
//	if (pp != NULL)
//		p = pp;
//	free(p);
//	p = NULL;
//	pp = NULL;
//	return 0;//���˳�ʱϵͳ���Զ����տռ�
//}

//��̬�ڴ泣���Ĵ���
//1.��NULL���н����ã� * ��  ������������
//2.�Կ��ٵĶ�̬�ڴ�ռ����Խ�����
//3.�ԷǶ�̬���ٵ��ڴ�����ͷ�
//���� int a = 0; int* p = &a; free(p);
//4.ʹ��free�ͷŲ��ֿ��ٵ��ڴ�ռ�
//5.��ͬһ���ڴ����ͷ�
//6.���ٵ��ڴ������ͷ�