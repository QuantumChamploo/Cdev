#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
	int* a;
	a = malloc(sizeof(int)*5);
	printf("the int array is: %d\n", *a);
	for(int i = 0; i < 3; i++)
	{
		*(a + i) = i;
	}
	int* p = &a[3];
	*p = 2147483647;
	for(int i = 0; i < 5; i++)
	{
		printf("%d\n", a[i]);
	}
}