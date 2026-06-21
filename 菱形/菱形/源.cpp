#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	//int  line = 0;
	//scanf("%d", &line);
	//int i = 0;
	//int j = 0;
	//for (i = 0;i < line;i++) 
	//{
	//	for (j = 0;j < line - i-1;j++) 
	//	{
	//			printf(" ");
	//	}
	//	for (j = 0;j < (2 * i) + 1;j++)
	//	{
	//			printf("*");
	//	}	
	//	printf("\n");		
 //   }			
	//	//for (j = 0;j < 2*line + 1;j++)
	//	//{
	//	//	printf("*");
	//	//}
	//	//printf("\n");
	//
	//for (i = 0;i < line-1;i++) //4 * 3***  2 *****5 1******* 7  0*********
	//{
	//	for(j=0;j<=i;j++)	
	//	{
	//		printf(" ");
	//	}
	//	for (j = 0;j < 2*(line-1-i)-1;j++)
	//	{
	//		printf("*");
	//	}
	//	printf("\n");
	//}
	int a = 0;
	int count = 0;//空瓶子的数量
	int sum = 0;//总共能买多少瓶
	printf("你的余额:");
	scanf("%d", &a);
	int tmp = a;
	while (a) 
	{
		if (a > 0) 
		{
			count++;
			a--;
			sum++;
		}
		if (count == 2)
		{
			a+=1;
			count = 0;
		}
	}
	printf("%d能买%d瓶汽水\n", tmp, sum);
	return 0;


}