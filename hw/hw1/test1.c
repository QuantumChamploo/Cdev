#include <stdio.h>
#include <string.h>

int main(void) {
	char destination[16] = "batman";
	char source[] = "spiderman";
	strcat(destination, source);
        printf("%s %s %lu %lu", destination, source, strlen(destination), strlen(source));
	return 0;
}