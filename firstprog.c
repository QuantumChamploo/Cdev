#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
char *str = malloc(50);
printf("Enter your CS login: ");
if (fgets (str, 50, stdin) == NULL)
fprintf(stderr, "Error reading user input.\n");
int len = strlen(str);
if (str[len - 1] == '\n') {
str[len - 1] = '\0';
}
printf("Your login: %s\n", str);
}