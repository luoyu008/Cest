#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//strstr���� 
//const char* strstr(const char* str1,const char* str2)
//�ú������ַ������Һ���   ������str1���Ƿ����str2  �����ҵ�����str1��str2�����ַ��ĵ�ַ ���򷵻�NULL
//ģ��ʵ��
//char* mystrstr(const char* str1, const  char* str2) {
//	//char* pstr1 =(char*) str1;
//	int count = 0;
//	while (*str2 != '\0'&&*str1!='\0') {
//		if (*str1 == *str2) {
//			count++;
//			str1++;
//			str2++;
//		}
//		else {
//			str2 -= count;
//			str1 = str1 - count + 1;
//			count = 0;
//		}
//
//	}
//	if (count == 0) {
//		return NULL;
//	}
//
//	return (char*)str1-count;
//}
//int main() {
//	char str1[] = "ahbgdc";
//	char str2[] = "abc";
//	char* ret=mystrstr(str1, str2);
//	printf("%s", ret);
//	return 0;
//}

//memcpy���� �ڴ濽������ ������������ڴ������  ���ܴ����ص��ڴ�Ŀ���
//void* memcpy(void* destination,const void* source,size_t num)
//�ú����ǽ�source�ڴ�����ݿ�����destination�ڴ���  ��С��num���ֽ�
//ģ��ʵ��
#include<assert.h>
//void* mymemcpy(void* des,const void* source,size_t num) {
//	assert(des && source);
//	void* pdes = des;
//	while (num--) {
//		*(char*)des = *(char*)source;
//		des = (char*)des + 1;
//		source = (char*)source + 1;
//	}
//	return pdes;
//}
//int main() {
//	unsigned int a[] = { 1,5,8,6,4967294 };
//	unsigned int b[50] = {0};
//	mymemcpy(b, a, sizeof(a));
//	return 0;
//}


//memmove���� �ڴ濽������ ����ʵ�ִ����ص��ڴ�Ŀ���
//void* memcpy(void* destination,const void* source,size_t num)
//ģ��ʵ��
//void* mymemmove(void* des,const void* src,size_t num){
//	assert(des && src);
//	void* pdes = des;
//	if (des < src) {
//		while (num--) {
//			*(char*)des = *(char*)src;
//			des = (char*)des + 1;
//			src = (char*)src + 1;
//		}
//	}
//	else {
//		while (num--) {
//			*((char*)des+num) = *((char*)src+num);
//		}
//	}
//	return des;
//}
//int main() {
//	 int a[] = { 1,5,8,6,4967294,4,3,7,9 };
//	//unsigned int b[50] = { 0 };
//	mymemmove(a, a, 16);
//	return 0;
//}
//strtok���� �ַ����ָ�
//char* strtok(char* str, const char* sep);
////str��Ҫ�ָ���ַ���  sep�Ƿָ���ַ���  
// str1���Դ��ַ����Ŀ����ַ���
//��strtok��һ��������ΪNULL��ʱ�� strtok�������ָ��ַ���ֱ����һ���ָ�� ���ָ�����Ϊ��\0��
//�����طָ���ַ�����һ���ַ��ĵ�ַ
//��strtok��һ������ΪNULL��ʱ��strtok���ڵڶ����ַ���ʼ�ָ��ַ���֪����һ���ָ�� ���ָ����Ϊ��\0��
//�����طָ���ַ�����Ϊ��\0������ʼ��ַ
//����ַ����в����зָ��� �����ؿ�ָ��

//int main() {
//	char str1[] = "zspdwa@asdfwa#wdas.awd";
//	const char* sep = "@#.";
//	char ss[50] = {0};
//	strcpy(ss, str1);
//	char* ret = NULL;
//	for (ret = strtok(ss, sep); ret != NULL; ret = strtok(NULL, sep)) {
//		printf("%s\n", ret);
//	}
//	return 0;
//}

//strerror����
//�Ѵ�����ת��Ϊ��Ӧ�Ĵ�����Ϣ
#include<errno.h>
//int main() {
//	FILE* p = fopen("test.text", "r");
//	if (p == NULL) {
//		printf("%s\n", strerror(errno));//errno��C�������õ�һ���������ŵ�ȫ�ֱ��� ��Ҫͷ�ļ�#include<errno.h>
//	}
//	else {
//		
//	}
//	return 0;
//}