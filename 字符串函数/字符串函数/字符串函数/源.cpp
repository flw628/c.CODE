#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <assert.h>
char*  my_strcat(char* dest, const char* src) 
{
	assert(dest && src);//模拟实现strcat
	char* ret = dest;
	while (*dest) 
	{
		dest++;
	}
	while (*dest++ = *src++);
	return ret;
}
int main() {
	char arr[20] = "hello ";
	//strcat(arr, "world");//strcat头文件string.h，在arr的\0处连接world，然后在结束位置自动补上\0
	my_strcat(arr, "world");
	printf("%s\n", arr);
	return 0;
}