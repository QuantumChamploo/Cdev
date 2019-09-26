#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *x = malloc(sizeof(int) * 5);
    for(int i = 0; i < 5; i++) {
        *(x+i) = i;
    }
	printf("%d ", *x);
	x += 2;
	printf("%d", x);
    return 0; 
}