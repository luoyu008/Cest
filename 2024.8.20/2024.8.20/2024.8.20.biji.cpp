#define _CRT_SECURE_NO_WARNINGS
#include"2024.8.20.h"
////�ļ��򿪺���
//FILE* fopen(const char* filename, const char* mode);  mode�С�r�������ļ�����w����д�ļ����������Ѿ����ڵ����ݣ�
// ��a�������ļ�����׷�����ݣ�
////�ļ��رպ���
//int fclose(FILE* stream);
// fputc���� �����ַ����뺯�� 
// int fputc ( int character, FILE * stream );
// int main() {
//FILE* pf = fopen("text.txt", "w");
//if (pf == NULL) {
//	printf("%s", strerror(errno));
//	return 1;
//}
//for (char i = 'a'; i < 'z'; i++) {
//	fputc(i, pf);
//}
//fclose(pf);
//pf = NULL;
//return 0;
//}
//fgetc����  �����ַ��������
//int main() {
//	FILE* pf = fopen("text.txt", "r");
//	if (pf == NULL) {
//		printf("%s", strerror(errno));
//		return 1;
//	}
//	int a = fgetc(pf);
//	printf("%c\n", a);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//fprintf����  ��ʽд��
//int fprintf(FILE* stream, const char* format, ...);
//typedef struct S
//{
//	char name[10];
//	int age;
//	char num[15];
//}s;
//int main() {
//	FILE* pf = fopen("text.txt", "a");
//	if (pf == NULL) {
//		printf("%s", strerror(errno));
//		return 1;
//	}
//	s ss = { "zsp",21,"17515083227" };
//	fprintf(pf, "%s %d %s", ss.name, ss.age, ss.num);
//	fprintf(stdout, "%s %d %s", ss.name, ss.age, ss.num);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
////fscanf����
//int fscanf(FILE* stream, const char* format, ...);
////sscanf����
//int sscanf(const char* s, const char* format, ...);
////sprintf����
//int sprintf(char* str, const char* format, ...);
//scanf��printf ����Ա�׼���������ĸ�ʽ�����
//fscanf��fprintf ��������������������ĸ�ʽ�����
//sscanf��sprintf �Ǵ�һ���ַ���ת����һ����ʽ�����ݺͰ�һ����ʽ������תΪ�ַ���

//fseek����  �����ļ�ָ���λ�ú�ƫ��������λ�ļ�ָ��Ӷ���ȡ����
//int fseek(FILE* stream, long int offset, int origin);
                            //ƫ����           λ��
//ftell����  �����ļ�ָ���������ʼλ�õ�ƫ����
//long int ftell(FILE* stream);
//rwind����  �ص��ļ�����ʼλ��
//void rewind(FILE* stream)