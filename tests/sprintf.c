#include <stdio.h>

int main(int argc,char * argv[]){
	char buffer[50];
	int a = 10, b = 20, c;
	c = a + b;
	sprintf(buffer, "sum for %i and %i is %i", a, b, c);
	// The string " sum of 10 and 20 is 30" is stored
	// into buffer instead of printing on stdout
	printf("%s", buffer);

	return 0;
}