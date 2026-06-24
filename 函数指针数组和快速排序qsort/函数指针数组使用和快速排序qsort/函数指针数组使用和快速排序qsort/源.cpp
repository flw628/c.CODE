#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int Add(int x, int y) {
	return x + y;
}
int Sub(int x, int y) {
	return x - y;
}
int Mul(int x, int y) {
	return x * y;
}
int Div(int x, int y) {
	return x / y;
}
int cmp_int(const void* e1, const void* e2)
{
	//e1写在e2前面就是升序，e2写在e1前面就是降序
	return *(int*)e2 - *(int*)e1;  //因为e1和e2是void * ，void *类型可以接收任何类型的地址，但不能直接解引用，所以要强制类型转换为int*
		//自定义比较回调函数
		//返回规则（核心）：
		//返回<0: e1 < e2
		//返回 0：e1 = e2
		//返回>0: e1 > e2
}
void menu()
{
	printf("************计算器*************\n");
	printf("*********1.add  2.sub**********\n");
	printf("*********3.mul  4.div**********\n");
	printf("*********0.exit      **********\n");
	printf("*******************************\n");
}
int main()
{
	int input;
	int (*pf[4])(int, int) = { Add,Sub,Mul,Div };//函数指针数组
	int x;
	int y;
	do
	{
		menu();
		printf("请输入:");
		scanf("%d", &input);	
		if (input == 0)
			printf("退出计算器\n");
		else if (input > 0 && input <= 4)
		{
			printf("请输入两个操作数:");
			scanf("%d%d", &x, &y);
			int ret = pf[input-1](x, y);
			printf("ret = %d\n", ret);
		}
		else
			printf("输入错误\n");
	} while (input);

	int(*(*pf1)[4])(int, int) = &pf; //指向函数指针数组的指针

		// void qsort(void* base,//你要排序的数据的起始位置
		//	          size_t num,//待排序的数据元素的个数
		//	          size_t width,//待排序的数据元素的大小（单位是字节）
		//	          int(*cmp)(const void* e1, const void* e2)//函数指针-比较函数 这个函数要自己写，然后qsort会按照自己函数定义的规则判断
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int); //qsort头文件是stdlib.h
	int i;
	for (i = 0;i < sz;i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}