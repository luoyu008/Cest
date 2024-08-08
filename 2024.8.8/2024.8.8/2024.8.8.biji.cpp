#define _CRT_SECURE_NO_WARNINGS
// char* a[]={"work","at","clbb"};
//char** pa=a;
//pa++;
// pa         a  
// char**---> char*--->"w"
//              char*--->"a"
//              char*--->"c"
//当pa++之后
//              char*--->"w"
//   char**--->char*--->"a"
//              char*--->"c"
//pa指向的是char*类型 所以pa++是指pa跳过一个char*类型  即指向了数组的下一个

//指针cpp[n]和cpp+n的坑
//char* c[] = { "entrt","new","point","first" };
//char** cp = { c + 3,c + 2,c + 1,c };
//char*** cpp = cp;
//printf("%s", **++cpp);
//这里输出first之后  因为++cpp相当于cpp + 了1 cpp向后挪了一个所以下面计算的时候要在此基础上计算
//printf("%s", *cpp[-1] + 3);
//这里输出的是st  因为cpp[-2]相当于求出的是cpp-了2的值  cpp本身并没有发生改变即cpp并没有像前挪动两个  
//所以后面的计算的时候要基于当前cpp的位置也就是最初cpp+了1的位置

//字符串函数
//strlen
//size_t(unsigned int) strlen(const char* s)
//返回的是无符号整型 返回的是直到遇到'\0'字符串的长度
//char s[] = "abc";
//strlen(s)//3
//char s[] = { 'a','c','b' };
//strlen(s)//此处是随机值  因为初始化是未初始化出’\0‘  所以strlen函数会一直向下读取知道遇到\0 
