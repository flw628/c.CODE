#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void menu() 
{
	printf("************  计算器  *************\n");
	printf("********** 1.Add  2.Sub************\n");
	printf("********** 3.Mul  4.Div************\n");
	printf("********** 0.退出计算器 ***********\n");
	printf("***********************************\n");
}
int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}
int calc(int(*pf)(int, int))//函数指针可以
{
	int a = 3;
	int b = 5;
	int ret = pf(a, b);
	return ret;
}
void calc1(int (*pf)(int, int))
{
	int a;
	int b;
	printf("请输入两个操作数:");
	scanf("%d %d", &a, &b);
	int ret = pf(a, b);//回调函数：用函数指针的方式往回调用函数
	printf("%d\n", ret);
}
int main() {
	int ret = calc(Add);
	int (*pf)(int, int) = &Add; //函数指针的写法，其中&add的&可以省略
	int (*pff)(int, int) = Add;
	int result = (*pf)(3, 4);//调用的时候可以不用解引用,要写*的话要括号括起来，（*pf）（3，4）相当于add（3，4）
	printf("result = %d\n", result);
	printf("ret = %d\n", ret);
	printf("%p\n",&Add);//add函数名代表函数的首元素地址，跟&add一样
	int a ;
	//计算器
	do 
	{
		menu();
		printf("请输入一个数:");
		scanf("%d", &a);
		switch (a) 
		{
		case 1:
			calc1(Add);
			break;
		case 2:
			calc1(Sub);
			break;
		case 3:
			calc1(Mul);
			break;
		case 4:
			calc1(Div);
			break;
		case 0:
			printf("退出计算器\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (a);
	return 0;
}