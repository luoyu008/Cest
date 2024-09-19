#define _CRT_SECURE_NO_WARNINGS
//最长的字母序连续子字符串的长度
int longestContinuousSubstring(char* s) {
    int i = 0;
    int len = strlen(s);
    int length = 1;
    int max = 0;
    for (i = 0; i < len - 1; i++) {
        if (s[i] == s[i + 1] - 1) {
            length++;
        }
        else
        {
            if (length > max) {
                max = length;
            }
            length = 1;
        }
    }
    if (length > max)
        max = length;
    return max;
}