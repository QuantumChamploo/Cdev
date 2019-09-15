#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int lv1 = 0;
	char lv2 = 'a';
	int num = lv2;
	printf("The integer is %d\n", num);
	printf("The value is %c\n", num);
	num += 1;
	char lv3 = num;
	printf("the next char is %c\n", lv3);
	printf("The value is %d\n", lv3);

}