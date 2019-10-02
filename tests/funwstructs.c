#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char firstname[22];
	char lastname[22];
	char position[22];
} Teammate;

typedef struct {
	int size;
	char name[22];
	Teammate roster[33];
} Team;

int main(){

	Team *team = malloc(sizeof(Team));

	Teammate player1 = {"joe","doe","forward"};
	team -> roster[0] = player1;
	printf("the first players last name is %s\n", (*(*team).roster).lastname);

	return 0;
}