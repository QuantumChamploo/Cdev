#include <stdio.h>

int main(){

	int a = 0;
	char str[32];
	printf("put in a number ");
	scanf("%i",&a);
	printf("the int %d\n",a);
	printf("the hex %x\n", a);
	printf("put in a string ");
	scanf("%s", str);
	printf("the string is %s\n", str);
	return 0;


}