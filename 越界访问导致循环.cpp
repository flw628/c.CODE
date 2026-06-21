#include <stdio.h>
int main() {
	int i = 0;
	int* p = &i;
	printf("%d\n", sizeof(p));
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	for (i = 0;i <= 12;i++) {
		printf("hehe\n");
		arr[i] = 0;
	}
} 