#define _CRT_SECURE_NO_WARNINGS
#include"2024.8.21.h"
//×î´óÖØ¸´×Ö·û´®
//int main() {
//    char str1[] = "ababc";
//    char str2[] = "ab";
//    int len1 = strlen(str1);
//    int len2 = strlen(str2);
//    int temp = len1 / len2;
//    char* str3 = (char*)malloc(sizeof(char) * len2 * temp);
//    if (str3 == NULL) {
//        perror("str3:");
//        return 1;
//    }
//    int max = 0;
//    str3[0] = '\0';
//    for (int i = 1; i <= temp; i++) {
//    strcat(str3, str2);
//    if (strstr(str1, str3) != NULL && i >= max)
//            max = i;
//    }
//    printf("%d", max);
//	return 0;
//}