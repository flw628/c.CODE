#include <stdio.h>
//指针数组-存放数组的地址
void print(int (*p)[5], int r, int c)//二维数组传参传的首元素地址，而首元素地址是二维数组的第一行，所以要数组指针来接收，类型是int (*)[10]
{
	int i;
	int j;
	for(i = 0; i<r;i++)
	{
		for (j = 0;j < c;j++)
		{
			printf("%d ", *(*(p + i) + j));//p+i就是访问数组第i行，*（p+i）获取里面的值,+j就是访问列，前面加*就是或第j列的值
		}
		printf("\n");
	}
}
int main()
{
	int arr1[] = { 1,2,3,4,5, };
	int arr2[] = { 2,3,4,5,6 };
	int arr3[] = { 3,4,5,6,7 };
	int* parr[3] = { arr1,arr2,arr3 };//数组指针
	printf("数组指针\n");
	int i;
	int j;
	for (i = 0; i < 3;i++)
	{
		for (j = 0;j < 5;j++) 
		{
			printf("%d ", *(parr[i] + j));
		}
		printf("\n");
	}

	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
	printf("指针数组\n");
	print(arr, 3, 5);
	return 0;
}