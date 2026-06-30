#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <errno.h>
int main() {
	//char* strstr(const char* str, const char* substr)->strstr的参数和返回类型
	const char* sep = "@.";//strstr函数会根据第一个传进去的参数str，找到str中的sep的第一个标记，然后将str找到的分隔符改为\0,并记录分割符的内存位置
	char email[] = "zhangpengwei@bitejiuyeke.com.net";
	char cp[40] = {0};
	strcpy(cp, email); // 拷贝一份，strtok会修改原字符串
	char* ret = NULL;
	for (ret = strtok(cp, sep);ret != NULL;ret = strtok(NULL, sep))
	{
		//如果strtok传入的第一个参数为空指针，函数将从同一个字符串中保存的位置开始，查找下一个标记
		printf("%s\n", ret);//strtok 如果记录的位置在\0之前，则\0后面的内存视为无效可访问段，直接返回空指针 NULL。
	}

	//printf("%s\n", strerror(1));//strerror是c语音的库函数，在执行库函数失败的时候，都会设置错误码
	//printf("%s\n", strerror(2));
	//printf("%s\n", strerror(3));
	//printf("%s\n", strerror(4));
	//printf("%s\n", strerror(5));
	//printf("%s\n", strerror(6));
	//printf("%s\n", strerror(7));
	//printf("%s\n", strerror(8));
	//printf("%s\n", strerror(9));
	FILE* pf = fopen("test.txt", "r");
	//fopen是打开文件的函数，第一个参数是文件的路径，r代表是以只读的方式打开，返回的是FILE*的指针
	//现在是相对路径，在自己创建文件的.c的路径下查找
	FILE* pf1 = fopen("C:\\Users\\xuyifeng\\Desktop\\test.txt", "r");//绝对路径的写法，要在\前面加上\，将单\转义为真正的\

	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		//errno是c语音设置的一个全局的错误码存放的变量，要用的时候要引头文件<errno.h>
		return 1;
	}
	if (pf1 != NULL)
	{
		printf("%s\n", "C:\\Users\\xuyifeng\\Desktop\\test.txt");
		return 1;
	}	
	return 0;
}