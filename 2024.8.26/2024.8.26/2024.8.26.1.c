#define _CRT_SECURE_NO_WARNINGS
#include"2024.8.26.h"
//atoiº¯ÊýÊµÏÖ
int main() {
    int flag = 1;
    long long temp = 0;
    char *s ="21474836460";
    int count = 0;
    //int a=pow()
    while (*s) {
        if (count != 0 && (*s < '0' || *s>'9'))
            break;
        if ((*s < '0' || *s>'9') && (flag == 2 || flag == -1))
            break;
        if (*s == '+') {
            flag = 2;
        }
        if ((*s < '0' || *s>'9') && *s != ' ' && *s != '+' && *s != '-') {
            break;
        }
        if (*s == '-' && temp == 0) {
            flag = -1;
            s++;
            continue;
        }

        if (*s == ' ') {
            s++;
            continue;
        }

        if (*s >= '0' && *s <= '9') {
            if (flag == 2) {
                temp = (temp * 10) + (flag / 2) * (*s - '0');
            }
            else
                temp = (temp * 10) + flag * (*s - '0');
            if ((int)temp != temp) {
                return (flag == 2 || flag == 1) ? INT_MAX : INT_MIN;
            }
            count++;
        }
        s++;

    }
    printf("%d", temp);
	return 0;
}