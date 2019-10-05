#include <stdio.h>

void func(void) {
    static int a = 10;
    a++;
    printf("%d ", a);
}

int main(void) {
    func();
    func();
    printf("\n");
    return 0;
}