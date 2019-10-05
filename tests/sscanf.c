#include <stdio.h>

int main(int argc, char *argv[]){
	char s[] = "3 red balls and 2 blue balls";
	char str[10], str2[10];
	int i;

	// %*s skips a word
	sscanf(s,"%i %*s %*s %*s %s %s", &i, str, str2);
	printf("%d %s %s\n", i, str, str2);
	
		
	return 0;
}