#include <stdio.h>
#include <stdlib.h>

void update(int *x) {
    int *a;
   a = malloc(sizeof(int));

	a = x;

	*x = 44;

    printf("%d ", *a);
}

int main(void) {
    int a = 11;
    int *b = &a;
    printf("%d ", *b);
    update(b);
    printf("%d ", *b);
    return 0;
}