#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//杨氏矩阵找数组 结构体方法
//#define row 3
//#define col 3
//struct f
//{
//	int x;
//	int y;
//};
//struct  f find(int a[row][col], int r, int c,int k)
//{
//	int x = 0;
//	int y = c - 1;
//	struct f m = { -1,-1 };
//	while (x <= r - 1 && y >= 0) {
//		if (k < a[x][y]) {
//			y--;
//		}
//		else if (k > a[x][y]) {
//			x++;
//		}
//		else if (k == a[x][y])
//		{
//			m.x = x;
//			m.y = y;
//			return m;
//		}
//	}
//	return m;
//}
//int main() {
//	int a[row][col] = { 1,2,3,4,5,6,7,8,9 };
//	int k = 0;
//	scanf("%d", &k);
//	struct f ret=find(a, 3, 3, k);
//	printf("%d %d\n", ret.x, ret.y);
//	return 0;
//}