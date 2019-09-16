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
		printf("the char in the function is %c\n", lv1);
		printf("the int in the function is %d\n", lv2);
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
		//printf("the char in the function is %c\n", lv5);

		//int lv4 = (-1 % 9);
		//printf("modulo test %d\n", lv4);
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
	int lv2 = *shift;
	printf("the message is %s\n", lv1);
	for(int i = 0; i < strlen(lv1); i++)
	{
		lv1[i] = swapLetter(shift, &(lv1[i]));
	}
	return lv1;
}

int main()
{
	int lv1 = -51;
	char lv2 = '!';
	int num = lv2;
	printf("The integer is %d\n", num);
	printf("The value is %c\n", num);
	num += 1;
	char lv3 = num;
	printf("the next char is %c\n", lv3);
	printf("The value is %d\n", lv3);
	printf("the char in the function is %c\n",swapLetter(&lv1, &lv2));
	char str1[] = "teststring";
	printf("the test string is %s\n", str1);
	int lv4 = strlen(str1);
	printf("the length of the test string is %d\n", lv4);
	for(int i = 0; i < lv4; i++)
	{
		printf("%c\n", str1[i]);
	}
	printf("the decoded message is %s\n", decodeMes(&lv1,str1));


	return 0;

}