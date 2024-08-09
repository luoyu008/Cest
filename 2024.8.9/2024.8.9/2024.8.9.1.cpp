#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//查找子序列
//char* mystrstr(const char* s, const  char* t,int len) {
//	//char* pstr1 =(char*) str1;
//	int count = 0;
//	int temp = 0;
//	if (len == 0)
//		return (char*)s;
//	while (*t != '\0' && *s != '\0') {
//		if (*s == *t) {
//			count++;
//			s++;
//			t++;
//			temp++;
//		}
//		else {
//			//str2 -= count;
//			t = t - count + 1;
//			count = 0;
//		}
//
//	}
//	if (temp != len) {
//		return NULL;
//	}
//
//	return (char*)s - count;
//}
//int main() {
//	char t[] = "ahbgdc";
//	char s[] = "bb";
//	int len = strlen(s);
//	char* ret = mystrstr(s, t,len);
//	if (ret == NULL)
//		printf("没有");
//	else
//		printf("有");
//	return 0;
//}

//字符串中单词数
int main() {
    const char* s = "Of all the gin joints in all the towns in all the world,   ";
    int count = 0;
    int temp = 0;
    int z = 0;
    const char* ps = s;
    int len = strlen(s);
    if (len == 0)
        printf("0");
    while (*s != '\0') {
        if (*s != ' ') {
            count++;
            s++;
            z++;
        }
        else if (count > 0) {
            count = 0;
            temp++;
            s++;
        }
        else
            s++;
    }
    if (z == 0)
        printf("0") ;
    if (*(ps + len-1) != ' ')
        temp += 1;
    printf("%d", temp);
    return 0;
}