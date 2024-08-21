#define _CRT_SECURE_NO_WARNINGS
#include"2024.8.20.h"
////文件打开函数
//FILE* fopen(const char* filename, const char* mode);  mode有‘r’（读文件）‘w’（写文件，会销毁已经存在的内容）
// ‘a’（在文件后面追加内容）
////文件关闭函数
//int fclose(FILE* stream);
// fputc函数 单个字符输入函数 
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
//fgetc函数  单个字符输出函数
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
//fprintf函数  格式写入
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
////fscanf函数
//int fscanf(FILE* stream, const char* format, ...);
////sscanf函数
//int sscanf(const char* s, const char* format, ...);
////sprintf函数
//int sprintf(char* str, const char* format, ...);
//scanf和printf 是针对标准输入和输出的格式化语句
//fscanf和fprintf 是针对所有输入和输出流的格式化语句
//sscanf和sprintf 是从一个字符串转化出一个格式化数据和把一个格式化数据转为字符串

//fseek函数  根据文件指针的位置和偏移量来定位文件指针从而读取数据
//int fseek(FILE* stream, long int offset, int origin);
                            //偏移量           位置
//ftell函数  返回文件指针相对于起始位置的偏移量
//long int ftell(FILE* stream);
//rwind函数  回到文件的起始位置
//void rewind(FILE* stream)