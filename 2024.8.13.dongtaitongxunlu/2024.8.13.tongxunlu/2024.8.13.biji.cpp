#define _CRT_SECURE_NO_WARNINGS
//ö��
#include"2024.8.13.con.h"
//typedef enum day
//{
//	mon=1,
//	tues,
//	wed,
//	thur,
//	fri,
//	sat,
//	sun,
//}day;
//����ĳ�Ա��ö�ٳ���
//�±�Ĭ�ϴ�0��ʼ
//int main() {
//	day d = mon;//��ʱ�ſ�ʼռ���ڴ�ռ�
//	//printf("%s", d);
//	int a[mon];
//	printf("%d\n", d);
//	printf("%d", mon);
//	return 0;
//}

//�����壨�����壩 ��Ա����һ��ռ� ��Ա��ͬʱʹ�� ��ռ��С���������ĳ�Ա�Ĵ�С
//union u
//{
//	char c;
//	int a;
//};
//int main() {
//	union u un;
//	printf("%d", sizeof(un));//4
//	return 0;
//}
// �������С�Ĺ�����ṹ��Ķ������һ��
//int key() {
//	union u {
//		char c;
//		int a;
//	}un;
//	un.a = 1;
//	return un.c;
//}
//int main() {
//	int ret = key();
//	if (ret == 1)
//		printf("x");
//	else printf("d");
//	return 0;
//}