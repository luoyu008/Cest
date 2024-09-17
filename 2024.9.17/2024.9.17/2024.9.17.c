#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define numRows 2
int main() {
    char* s = "ABC";
    int len = (int)strlen(s);
    if (numRows <= 1 || len <= numRows)
        return s;
    int num = numRows + numRows - 2;
    int col = (numRows-1) * (len / num) + ((len % num) / numRows>0 ? 1 + (len % num) % numRows : 1);
    char str[numRows][2];
    int i = 0;
    int j = 0;
    for (i = 0; i < numRows; i++) {
        for (j = 0; j < col; j++) {
            str[i][j] = '1';
        }
    }
    //int direction=0;
    i = 0;
    for (j = 0; j < col; j++) {
        if (j % (numRows - 1) == 0) {
            for (i=0; i < numRows && *s != '\0'; i++) {
                str[i][j] = *s;
                s++;
            }
        }
        if (numRows >= 3) {
            while (*s != '\0' && j % (numRows - 1) != 0) {
                if (i == numRows) {
                    i = i - 2;
                    str[i][j] = *s;
                    s++;
                    break;
                }
                else if (i >= 1) {
                    i = i - 1;
                    str[i][j] = *s;
                    s++;
                    break;
                }
            }
        }

    }
    char* str1 = (char*)malloc(1001*sizeof(char));
    int m = 0;
    for (i = 0; i < numRows; i++) {
        for (j = 0; j < col; j++) {
            if (str[i][j] != '1') {
                str1[m++] = str[i][j];
            }
        }
    }
    str1[m] = '\0';
	return 0;
}