#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 128

void bufferFill(FILE *, char *);
void inputBuffering(char *);
void identifiers(char *, char *);

int main(int argc, char const *argv[]){
	char buffer[BUFFER_SIZE], filename[64] = "input.txt";
	FILE *filePtr;
	int i;

	memset(buffer, 0, sizeof(buffer));		// initializing the buffer (emptying)
	filePtr = fopen(filename, "rb");
	if (filePtr == NULL){
        printf("Cannot open file \n");
        exit(0);
    }

    bufferFill(filePtr, buffer);

    for (i = 0; i < strlen(buffer) && i < BUFFER_SIZE; ++i)
    	printf(buffer[i] == EOF ? "<EOF>" : "%c", buffer[i]);

    printf("\nTotal Number of Characters read: %d\n", i);
    fclose(filePtr);

    inputBuffering(buffer);
	return 0;
}

// Fills the Buffer
void bufferFill(FILE *filePtr, char *buffer){
	int buffer_i=0, ch;
    while ((ch = fgetc(filePtr)) != EOF && buffer_i <= BUFFER_SIZE)
        buffer[buffer_i++] = ch;
    buffer[buffer_i] = EOF;
}

void inputBuffering(char *buffer){
	char *lexemeBegin=&buffer[0], *fp=&buffer[0];
	char specialCharacters[BUFFER_SIZE];
	int str_i=0;

	memset(specialCharacters, 0, sizeof(specialCharacters));		// initializing the specialCharacters (emptying)

    for (int i = 0; i < strlen(buffer) && i < BUFFER_SIZE; ++i){
    	fp=&buffer[i];
    	if (*fp == '+' || *fp == '*' || *fp == '-' || *fp == '/' || *fp == '%' || *fp == '=' || *fp == ',' || *fp==';'){
    		specialCharacters[str_i++] = buffer[i];
    		identifiers(lexemeBegin, fp);
    		lexemeBegin=&buffer[i+1];
    		fp=&buffer[i+1];
    	}
    	else if (*fp == ' ' || *fp == '\t' || *fp == '\n'){
    		identifiers(lexemeBegin, fp);
    		lexemeBegin=&buffer[i+1];
    		fp=&buffer[i+1];
    	}
    }
    printf("Operators: %s\n", specialCharacters);
}

// iter moves through lexemeBegin and fp printing the identifier
void identifiers(char *lexemeBegin, char *fp){
	char *iter = lexemeBegin;
	printf(lexemeBegin != fp ? "Identifier: " : "");
	while(iter != fp){
		printf("%c", *iter);
		iter++;
	}
	printf(lexemeBegin != fp ? "\n" : "");
}