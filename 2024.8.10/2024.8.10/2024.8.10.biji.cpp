#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//memcmp����  �ڴ�ȽϺ���
//int memcmp(void* s1, conat void* s2,size_t num)
//�ú����ǱȽ�num���ֽ�s1��s2���ڴ��ڵ����ݵĴ�С
//s1>s2ʱ  ����>0����
//  =          =
//  <          <
//int main() {
//	int a[] = { 1,3,3,4,5,6 };
//	int b[] = { 1,4,3 };
//	int ret = memcmp(a, b, 12);
//	printf("%d", ret);
//	return 0;
//		
//}

//memset���� �ڴ����ú���  ���ֽ�Ϊ��λ
//void* memset(void* ptr,int value,size_t num)
//int main() {
//	char s1[] = "zspzuishuai";
//	memset(s1, 'a', 7);
//	printf("%s", s1);
//	return 0;
//}