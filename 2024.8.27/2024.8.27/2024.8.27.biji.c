#define _CRT_SECURE_NO_WARNINGS
#include"2024.8.273.h"
//递归算法时间复杂度次数分析：递归次数*每次递归调用的次数

//空间复杂度计算的是程序里临时的额外占用空间的变量个数 也可以使用大O渐进法

//顺序表就是数组  但是在数组的基础上要求数据是从头开始连续存储的不能间隔跳跃

//初始化
void SeqlistInit(s* s1) {
	s1->a = NULL;
	s1->size = 0;
	s1->capactity = 0;
}
////初始开辟空间
//void Seqlistm(s* s1) {
//	s1->a =(SLdatetype*) malloc(sizeof(SLdatetype) * 2);
//	s1->capactity = 2;
//}
//增容
void Seqlistmm(s* s1) {
	int new = s1->capactity * 2;
	SLdatetype * l = (SLdatetype*)realloc(s1->a,(new==0?4:new)*sizeof(SLdatetype));
	if (l == NULL) {
		printf("%s\n", strerror(errno));
		return;
	}
	else
		s1->a = l;
	if (new == 0) {
		s1->capactity = 4;
	}else
	s1->capactity *= 2;
}
//表尾插入
void SeqlistPushBack(s* s1) {
	SLdatetype x = 0;
		printf("请输入要插入的值：\n");
	scanf("%d", &x);
	if (s1->size == s1->capactity) {
		Seqlistmm(s1);
	}
	
	s1->a[s1->size] = x;
	s1->size += 1;
}
//销毁表
void Seqlistdestory(s* s1) {
	free(s1->a);
	s1->a = NULL;
}
//表尾删除
void SeqlistPopBack(s* s1) {
	/*if (s1->size != 0) {
		s1->size--;
	}*/
	assert(s1->size > 0);
	s1->size--;
}

;//表头插入
void SeqlistPushFront(s* s1) {
	SLdatetype x = 0;
	printf("请输入要插入的值：\n");
	scanf("%d", &x);
	s1->size++;
	if (s1->capactity == s1->size) {
		Seqlistmm(s1);
	}
	for (int i = s1->size-1; i >=1; i--) {
		s1->a[i] = s1->a[i - 1];
	}
	s1->a[0] = x;
}

;//表头删除
void SeqlistPopFront(s* s1) {
	//assert(s1->size > 0);
	if (s1->size > 0) {
		for (int i = 0; i < s1->size; i++) {
			s1->a[i] = s1->a[i + 1];
		}
		s1->size--;
	}
}

;//打印测试
void SeqlistPrintf(s* s1) {
	for (int i = 0; i < s1->size; i++) {
		printf("%d ", s1->a[i]);
	}
	printf("\n");
}
//找到x的位置并返回
void SeqlistFind(s* s1) {
	SLdatetype x = 0;
	printf("请输入要查找的值：\n");
	scanf("%d", &x);
	int i = 0;
	for ( i = 0; i < s1->size; i++) {
		if (s1->a[i] == x) {
			printf("该数据的位置是：%d\n", i + 1);
			break;
		}
	}
	if (i == s1->size)
		printf("未找到该数据！\n");

}
//删除x位置的数据
void SeqlistPopn(s* s1) {
	int n = 0;
	printf("请输入你要删除的位置：\n");
	scanf("%d", &n);
	if (n <= s1->size&&n>0) {
		for (int i = n - 1; i < s1->size - 1; i++) {
			s1->a[i] = s1->a[i + 1];
		}
		s1->size--;
	}
	else
		printf("位置无效！\n");
}

//插入n位置一个数据
void SeqlistPushn(s* s1) {
	SLdatetype x = 0;
	int n = 0;
	printf("请输入你要插入的位置：\n");
	scanf("%d", &n);
	printf("请输入你要插入的数据：\n");
	scanf("%d", &x);
	if (n > 0 && n <= s1->size+1) {
		
		s1->size++;
		if (s1->size == s1->capactity) {
			Seqlistmm(s1);
		}
		if (n == s1->size + 1) {
			s1->a[s1->size-1] = x;
		}else
		for (int i = s1->size-1; i >=n-1; i--) {
			s1->a[i] = s1->a[i -1];
		}
		s1->a[n - 1] = x;
	}
	else
		printf("位置无效！\n");
}