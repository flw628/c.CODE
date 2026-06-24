#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stu {
	char name[20];
	int age;
};
int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;//升序
}
int cmp_stu_by_name(const void* e1, const void* e2)
{
	return strcmp(( (struct stu*) e1 )->name,( (struct stu*) e2 )->name);
}
void Swap(char* buff1,char*buff2, int width)
{
	int i;
	char tmp;
	for (i = 0;i < width;i++)
	{
		//buff1、buff2 都是 char*，每次自增只移动 1 个字节；
		//width 是数组单个元素的总字节大小（int 就是 4、double 就是 8、结构体看 sizeof）。
		//作用：把两块长度为 width 字节的内存完整互换内容。
		tmp = *buff1;
		*buff1 = *buff2;
		*buff2 = tmp;
		buff1++;
		buff2++;
		//这段代码不关心你存的是 int、long、结构体、字符串，只根据传入的字节宽度 width，逐字节交换整块内存。
		//这就是模仿库函数 qsort 能排序任意数据类型的关键。
	}
}
void bubble_sort(void*base,int num,int width,int(*cmp)(const void*e1,const void*e2)) 
{
	int i;
	int j;
	int flag;// 标记本轮是否有序
	for (i = 0;i < num - 1;i++) 
	{
		flag = 1;// 先假设本轮有序
		for (j = 0;j < num - 1 - i;j++)
		{
			//base+j因为base被强制转换为char*类型，一次只能走一个字节，乘以width如果加一就相等于跳过一整个元素
			//这样无论传的是什么类型的参数都能精准跳过一个元素
			if (cmp((char*)base + j * width, (char*)base + (j + 1)*width) > 0) 
			{
				Swap((char*)base + j * width, (char*)base + (j + 1)* width, width);
				flag = 0;// 发生交换，数组无序
			}
		}
		//本轮无交换，提前退出排序
		if (flag == 1)
		{
			break;
		}
	}
}
void test1() 
{
	int i;
	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
	for (i = 0;i < sz;i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void test2() 
{
	struct stu s[] = { {"zhangsan",23},{"lisi",30},{"wangwu",25} };
	int sz = sizeof(s) / sizeof(s[0]);
	bubble_sort(s, sz, sizeof(s[0]), cmp_stu_by_name);
	int i;
	for (i = 0;i < sz;i++) 
	{
		printf("%s ", s[i].name);
	}
	printf("\n");
}
int main() {
	test1();
	test2();
	return 0;
}