#include <stdio.h>

int count = 10;

void func(int count) {
    count++;
    printf("%d  ", count);
}
int main(void) {
    func(count);
    func(count);
    printf("\n");
    return 0;
}