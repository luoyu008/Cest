#define _CRT_SECURE_NO_WARNINGS
#include"2024.8.20.h"
int cmp(const char* str1,const char* str2) {
    int temp = 1;
    while (*str2 != '\0') {
        if (*str1 != *str2) {
            temp = 0;
            break;
        }
        str1++;
        str2++;
    }
    return temp;
}
int main() {
	 const char* str1 = "aaabaaaabaaabaaaabaaaabaaaabaaaaba";
	 const char* str2 = "aaaba";
    int count = 0;
    int a[100];
    int i = 0;
    while (*str1 !='\0') {
        if (cmp(str1, str2) == 1) {
            count++;
            str1 += strlen(str2);
        }
        else {
            a[i] = count;
            count = 0;
            i++;
            str1++;
        }
    }
    a[i] = count;
    int max = a[0];
    for (int j = 0; j < i; j++) {
        if (a[j] > max)
            max = a[j];
    }
    printf("%d", max);
	return 0;
}