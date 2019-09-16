#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char swapLetter(int* shift, char* let )
{

	char lv1 = *let;
	int lv2 = lv1;
	int lv3 = *shift;
	if(lv1 != '.' && lv1 != '!'  && lv1 != ',' && lv1 != '?' && lv1 != ';' && lv1 != ' ')
	{

		lv2 -= 96;
		lv2 += lv3;
		while(lv2 < 0)
		{
			lv2 += 26;
		}
		while(lv2 > 26)
		{
			lv2 -= 26;
		}
		lv2 += 96;
		char lv5 = lv2;

		return lv5;
	}
	else
	{
		return lv1;
	}
	
}
char* decodeMes(int* shift, char mes[])
{
	char* lv1 = mes;

	printf("the message is %s\n", lv1);
	for(int i = 0; i < strlen(lv1); i++)
	{
		lv1[i] = swapLetter(shift, &(lv1[i]));
	}
	return lv1;
}

int main()
{
	int lv1 = 1;
	char lv2 = 'a';
	printf("the character is %c\n", lv2);
	printf("the next character is %c\n", swapLetter(&lv1, &lv2));
	char str1[] = "test string?!";
	printf("the test string is %s\n", str1);
	printf("the decoded message is %s\n", decodeMes(&lv1,str1));

	return 0;


}
