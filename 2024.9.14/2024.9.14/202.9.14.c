#define _CRT_SECURE_NO_WARNINGS
//���ַ������Ƴ�*�Լ�*����ַ�
char* removeStars(char* s) {
    char* str = (char*)malloc(sizeof(char) * 100001);
    int j = 0;
    while (*s != '\0') {
        if (*s != '*')
        {
            str[j++] = *s;
        }
        else
        {
            j--;
        }
        s++;
    }
    str[j] = '\0';
    return str;
}