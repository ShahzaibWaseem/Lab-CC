#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PROD_SIZE 256
#define NUM_PROD 10

void checkRecursion(char [NUM_PROD][PROD_SIZE], int);
void removeRecursion(char, char, char);

int main(int argc, char const *argv[]){
	char productions[NUM_PROD][PROD_SIZE], c;
	int num_productions;

	printf("Enter the number of productions: ");
	scanf("%d", &num_productions);

	while((c = getchar()) != '\n' && c != EOF);

	printf("Enter productions (A->a|BC):\n");
	for(int i = 0; i < num_productions; i++){
		fgets(productions[i], PROD_SIZE, stdin);
		// remove \n
		strtok(productions[i], "\n");
	}

	checkRecursion(productions, num_productions);
	return 0;
}

void checkRecursion(char productions[NUM_PROD][PROD_SIZE], int num_productions){
	char first;
	int iter;

	for (int i = 0; i < num_productions; ++i){
		first = productions[i][0];		// takes the "producer" (left of the ->)
		iter = 3;						// takes it after ->
		printf("\n%d Production:\t%s\n", i+1, productions[i]);

		while(iter < strlen(productions[i])){
			if (first == productions[i][iter]){
				printf("Left Recursion\n");

				int index = iter;
				while(productions[i][index]!='|' && index < strlen(productions[i]))
					index++;
				removeRecursion(first, productions[i][iter+1], productions[i][index+1]);
				break;
			}
			while(productions[i][iter] != '|' && iter < strlen(productions[i]))
				iter++;
			iter++;
		}
		if(iter >= strlen(productions[i]))
			printf("No Left Recursion\n");
	}
}

void removeRecursion(char first, char alpha, char beta){
	printf("Removing Left Recursion\n");
	printf("%c->%c%c\'", first, beta, first);
	printf("\n%c\'->%c%c\'\n", first, alpha, first);
}