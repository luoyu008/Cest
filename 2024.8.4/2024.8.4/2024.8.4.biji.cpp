#define _CRT_SECURE_NO_WARNINGS
//����ָ�� 
// void add��int��{}
// int ��*p����int��=add��
// (*(void(*)())0)();   �ñ��ʽ�Ƕ�0����ǿ������ת��Ϊ ����ֵΪvoid ���βεĺ���ָ��ĵ�ַ 
// ͬʱ����0��ַ���ĸú���  Ҳ��д��(void(*)())0()   0Ҳ�����Ϊ0x00000000
//void(* signal(int ,void(*)(int)))(int);
//signal��һ��������  ���ϴ�����һ����������  ������signal�����ĵ�һ������Ϊint����  
// �ڶ�������Ϊ ����ֵΪvoid ��������Ϊint�ĺ���ָ�� signal�����ķ�������Ҳ��void  ����Ϊint�ĺ���ָ��
typedef void(*pf)(int);
//�ô���Ҳ������������Ϊ pf(* signal(int,pf))
//����ָ��ļ���Сʵ�� ���׼�����
//�ص�����

//����ָ�������������д
//int (*p[4])(int,int)={add,sub,mul,div};
//������ѭ����ͨ��*p[i](8,4)�������ε����ĸ�����
//����ָ������ָ��
//int (*(*pp)[4])(int,int)=&p;
#include<stdio.h>
void menu() {
	printf("**********************\n");
	printf("******   1.add   *****\n");
	printf("******   2.sub   *****\n");
	printf("******   3.mul   *****\n");
	printf("******   4.div   *****\n");
	printf("******   0.exit  *****\n");
	printf("**********************\n");
}
int add(int x, int y) {
	return x + y;
}
int sub(int x, int y) {
	return x - y;
}
int mul(int x, int y) {
	return x * y;
}
int div(int x, int y) {
	return x / y;
}
//����ָ��
//void calc(int (*p)(int ,int)) {
//	printf("������������\n");
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int ret = p(a, b);
//	printf("%d\n" ,ret);
//}
//����ָ������
void calc(int (*p[5])(int ,int), int inpute, int x, int y) {
	            printf("�����룺\n");
				scanf("%d %d", &x, &y);
				int ret = p[inpute](x, y);
				printf("%d\n", ret);
}
int main() {
	int inpute = 0;
	//����ָ������ʵ��  ����ָ������Ҳ����ת�Ʊ�ͨ�������±������ú���
	do {
		menu();
		printf("������ѡ��:\n");
		scanf("%d", &inpute);
		int x = 0;
		int y = 0;
		int (*p[5])(int, int) = { 0,add,sub,mul,div };
		if (inpute == 0) {
			printf("�˳�\n");
		}
		else if (inpute > 4) {
			printf("����������\n");
		}
		else {
			calc(p, inpute, x, y);
		}
	} while (inpute);
//	/*do
//	{*/
//	/*menu();
//	printf("������:\n");
//	scanf("%d", &inpute);*/
//	//����ָ��
////		switch (inpute)
////		{
////		case 1:
////			calc(add);
////			break;
////		case 2:
////			calc(sub);
////			break;
////		case 3:
////			calc(mul);
////
////			break;
////		case 4:
////			calc(div);
////			break;
////		case 0:
////			printf("�˳�\n");
////			break;
////		default:
////			printf("����������\n");
////			break;
////		}
////	} while (inpute);
//
//
//	return 0;
////}
}