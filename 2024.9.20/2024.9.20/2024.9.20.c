#define _CRT_SECURE_NO_WARNINGS
//统计特殊整数
//输入：n = 20
//输出：19
//解释：1 到 20 之间所有整数除了 11 以外都是特殊整数。所以总共有 19 个特殊整数。
#include <stdio.h>
#define MAX_M 11
#include <stdlib.h>
#include <stdbool.h>
int memo[MAX_M][1 << 10];
int dfs(int i, int mask, bool is_limit, bool is_num, const char* s) {
    if (s[i] == '\0') {
        return is_num; // is_num 为 true 表示得到了一个合法数字
    }
    if (!is_limit && is_num && memo[i][mask] != -1) {
        return memo[i][mask]; // 之前计算过
    }
    int res = 0;
    if (!is_num) { // 可以跳过当前数位
        res = dfs(i + 1, mask, false, false, s);
    }
    // 如果前面填的数字都和 n 的一样，那么这一位至多填数字 s[i]（否则就超过 n 啦）
    int up = is_limit ? s[i] - '0' : 9;
    // 枚举要填入的数字 d
    // 如果前面没有填数字，则必须从 1 开始（因为不能有前导零）
    for (int d = is_num ? 0 : 1; d <= up; d++) {
        if ((mask >> d & 1) == 0) { // d 不在 mask 中，说明之前没有填过 d
            res += dfs(i + 1, mask | (1 << d), is_limit && d == up, 1, s);
        }
    }
    if (!is_limit && is_num) {
        memo[i][mask] = res; // 记忆化
    }
    return res;
}
int main() {
    int n = 20;
    char s[MAX_M];
    sprintf(s, "%d", n); // 将数字 n 转换为字符串
    int m = strlen(s);
    memset(memo, -1, m * (1 << 10) * sizeof(int)); // -1 表示没有计算过
    return dfs(0, 0, true, false, s);
	return 0;
}