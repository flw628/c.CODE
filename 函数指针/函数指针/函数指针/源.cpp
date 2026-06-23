#include <stdio.h>
int add(int x, int y)
{
	return x + y;
}
int calc(int(*pf)(int, int))//函数指针可以
{
	int a = 3;
	int b = 5;
	int ret = pf(a, b);
	return ret;
}
int main() {
	int ret = calc(add);
	int (*pf)(int, int) = &add; //函数指针的写法，其中&add的&可以省略
	int (*pff)(int, int) = add;
	int result = (*pf)(3, 4);//调用的时候可以不用解引用,要写*的话要括号括起来，（*pf）（3，4）相当于add（3，4）
	printf("result = %d\n", result);
	printf("ret = %d\n", ret);
	return 0;
}