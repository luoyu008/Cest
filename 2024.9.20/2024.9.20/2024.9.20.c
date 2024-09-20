#define _CRT_SECURE_NO_WARNINGS
//ͳ����������
//���룺n = 20
//�����19
//���ͣ�1 �� 20 ֮�������������� 11 ���ⶼ�����������������ܹ��� 19 ������������
#include <stdio.h>
#define MAX_M 11
#include <stdlib.h>
#include <stdbool.h>
int memo[MAX_M][1 << 10];
int dfs(int i, int mask, bool is_limit, bool is_num, const char* s) {
    if (s[i] == '\0') {
        return is_num; // is_num Ϊ true ��ʾ�õ���һ���Ϸ�����
    }
    if (!is_limit && is_num && memo[i][mask] != -1) {
        return memo[i][mask]; // ֮ǰ�����
    }
    int res = 0;
    if (!is_num) { // ����������ǰ��λ
        res = dfs(i + 1, mask, false, false, s);
    }
    // ���ǰ��������ֶ��� n ��һ������ô��һλ���������� s[i]������ͳ��� n ����
    int up = is_limit ? s[i] - '0' : 9;
    // ö��Ҫ��������� d
    // ���ǰ��û�������֣������� 1 ��ʼ����Ϊ������ǰ���㣩
    for (int d = is_num ? 0 : 1; d <= up; d++) {
        if ((mask >> d & 1) == 0) { // d ���� mask �У�˵��֮ǰû����� d
            res += dfs(i + 1, mask | (1 << d), is_limit && d == up, 1, s);
        }
    }
    if (!is_limit && is_num) {
        memo[i][mask] = res; // ���仯
    }
    return res;
}
int main() {
    int n = 20;
    char s[MAX_M];
    sprintf(s, "%d", n); // ������ n ת��Ϊ�ַ���
    int m = strlen(s);
    memset(memo, -1, m * (1 << 10) * sizeof(int)); // -1 ��ʾû�м����
    return dfs(0, 0, true, false, s);
	return 0;
}