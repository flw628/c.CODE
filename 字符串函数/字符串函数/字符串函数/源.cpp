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
char* my_strstr(const char* str, const char* substr)
{
	assert(str && substr);
	const char* ret =str;
	const char* p1 = str;
	const char* p2 = substr;
	while(*p1)
	{
		p1 = ret;
		p2 = substr;
		while (*p1 != '\0' && *p2 != '\0' && *p1 == *p2)
		{
			p1++;
			p2++;
		}
		if (*p2 == '\0')
		{
			return (char*)ret;
		}
		ret++;
	}
	return NULL;

}
int main() {
	char arr[20] = "hello ";
	//strcat(arr, "world");//strcat头文件string.h，在arr的\0处连接world，然后在结束位置自动补上\0
	my_strcat(arr, "world");
	printf("%s\n", arr);

	char s1[] = "abbbcef";
	char s2[] = "bbc";
	//char* ret = strstr(s1, s2);//strstr在一个主字符串里查找子字符串第一次出现的位置。
	char* ret1 = my_strstr(s1, s2);
	//char* strstr(const char* str, const char* substr);
	//  参数 1 str：被搜索的主字符串
	//	参数 2 substr：要找的子串
	//	返回值：
	//	找到：返回子串首次出现的起始指针
	//	没找到：返回 NULL
	//	如果 substr 是空字符串 ""，直接返回 str
	//printf("%s\n", ret);
	printf("%s\n", ret1);
	return 0;
}