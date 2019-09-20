#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int testFunc1();
int testFunc2();


int main()
{
	int c = testFunc1();
	printf("%d\n", c);

	return 0;
}

int testFunc1()
{
	int a = 7;
	int c = testFunc2();
	//free(&c);
	return a;
}

int testFunc2()
{
	int b = 8;
	int d = testFunc1();
	//free(&d);
	return b;
}

