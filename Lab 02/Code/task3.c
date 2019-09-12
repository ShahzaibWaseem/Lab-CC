#include <stdio.h>
#include <string.h>

#define STRING_SIZE 10

void identifiers(char []);

int main(int argc, char const *argv[]){
	char input[STRING_SIZE];
	int numLines=-1;
	printf("Enter lines here\n(Press q to stop entering lines)\n");
	while(1){
		printf("\nInsert Statement: ");
		fgets(input, STRING_SIZE, stdin);
		numLines++;
		if (input[0] == 'q')
			break;
		else
			identifiers(input);
	}
	printf("Number of Lines: %d\n", numLines);
	return 0;
}

void identifiers(char input[]){
	char specialCharacters[STRING_SIZE];
	int str_i = 0;
	for (int i = 0; i < strlen(input); ++i){
		if((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))
			printf("%c is an identifier\n", input[i]);
		if (input[i] == '+' || input[i] == '*' || input[i] == '-' || input[i] == '/' || input[i] == '%'){
			specialCharacters[str_i] = input[i];
			str_i++;
		}
	}
	printf("Special Characters: ");
	for (int i = 0; i < strlen(specialCharacters); ++i){
		printf("%c ", specialCharacters[i]);
	}
	printf("\n");
}