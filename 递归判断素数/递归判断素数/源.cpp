#include <math.h>
#include <stdio.h>
void Is() {
	int i = 0;
	int j;
	for(j = 101;j<=200;j+= 2){
		for (i = 2;i <= sqrt(j);i++) 
		{
			if (j % i == 0) {
				break;
			}
		}
		if (i > sqrt(j))
			printf("%d ", j);
	}	
}
void Is_(int j) {
	int i;
	for (i = 2;i <= sqrt(j);i++) {
		if (j % i == 0)
			break;
	}
	if(i > sqrt(j))
	printf("%d ", j);
	if(j <=200)
		Is_(j + 2);
}
int main() {
	Is_(101);
	return 0;
}