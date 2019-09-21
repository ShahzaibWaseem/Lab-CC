#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 32

void bufferFill(FILE *, char *, char *);
void bufferPairs(char *, char *);
void identifiers(char *, char *, char *, char [], char [], int *, int *);

int main(int argc, char const *argv[]){
	char buffer1[BUFFER_SIZE], buffer2[BUFFER_SIZE], filename[64] = "input.txt";
	FILE *filePtr;
	int i, j;

	memset(buffer1, 0, sizeof(buffer1));		// initializing the buffer1 (emptying)
	memset(buffer2, 0, sizeof(buffer2));		// initializing the buffer2 (emptying)

	filePtr = fopen(filename, "rb");
	if (filePtr == NULL){
        printf("Cannot open file \n");
        exit(0);
    }
    bufferFill(filePtr, buffer1, buffer2);

    // if an EOF is encountered insert <EOF>
    printf("Buffer 1\n");
    for (i = 0; i < strlen(buffer1) && i < BUFFER_SIZE; ++i)
    	printf(buffer1[i] == EOF ? "<EOF>" : "%c", buffer1[i]);
    printf("\nNumber of Characters in Buffer 1: %d\n", i);

    // if an EOF is encountered insert <EOF>
    printf("\nBuffer 2\n");
    for (j = 0; j < strlen(buffer2) && j < BUFFER_SIZE; ++j)
    	printf(buffer2[j] == EOF ? "<EOF>" : "%c", buffer2[j]);
    printf(j == 0 ? "Buffer 2 is empty\n" : "\nNumber of Characters in Buffer 2: %d\n", j);
    printf("\nTotal Number of Characters in both Buffers: %d\n", i+j);

    fclose(filePtr);

    bufferPairs(buffer1, buffer2);
	return 0;
}

void bufferFill(FILE *filePtr, char *buffer1, char *buffer2){
	int buffer_i=0, ch;
    while (buffer_i < BUFFER_SIZE && (ch = fgetc(filePtr)) != EOF)
        buffer1[buffer_i++] = ch;
    if(buffer_i < BUFFER_SIZE)
    	buffer1[buffer_i] = EOF;
    else{
	    buffer_i=0;
	    while (buffer_i < BUFFER_SIZE && (ch = fgetc(filePtr)) != EOF)
	        buffer2[buffer_i++] = ch;
	    buffer2[buffer_i] = EOF;
	}
}

void bufferPairs(char *buffer1, char *buffer2){
	char *lexemeBegin=&buffer1[0], *fp=&buffer1[0];
	char specialCharacters[BUFFER_SIZE], identifier[BUFFER_SIZE*2];
	int *sc_i=0, *iden_i=0, temp_i=0;

	memset(specialCharacters, 0, sizeof(specialCharacters));		// initializing the specialCharacters (emptying)
	memset(identifier, 0, sizeof(identifier));						// initializing the identifier (emptying)

    identifiers(buffer1, lexemeBegin, fp, specialCharacters, identifier, &sc_i, &iden_i);
    identifiers(buffer2, lexemeBegin, fp, specialCharacters, identifier, &sc_i, &iden_i);
    temp_i=iden_i;
    identifier[temp_i-1]='\0';

    printf("\nIdentifiers\t:\t%s\n", identifier);
    printf("Operators\t:\t%s\n", specialCharacters);
}

void identifiers(char *buffer, char *lexemeBegin, char *fp, char specialCharacters[], char identifier[], int *sc_i, int *iden_i){
	for (int i = 0; i < strlen(buffer) && i < BUFFER_SIZE; ++i){
    	fp=&buffer[i];
    	if (*fp == '+' || *fp == '*' || *fp == '-' || *fp == '/' || *fp == '%' || *fp == '=' || *fp == ',' || *fp==';'){
    		specialCharacters[*sc_i] = buffer[i];
    		if(lexemeBegin != fp){
    			identifier[*iden_i] = ',';
    			*iden_i=*iden_i+1;
    		}
    		lexemeBegin=&buffer[i+1];
    		fp=&buffer[i+1];
    		*sc_i=*sc_i+1;
    	}
    	else if (*fp == ' ' || *fp == '\t' || *fp == '\n'){
    		if(lexemeBegin != fp){
    			identifier[*iden_i] = ',';
    			*iden_i=*iden_i+1;
    		}
    		lexemeBegin=&buffer[i+1];
    		fp=&buffer[i+1];
    	}
    	else if(*fp != EOF){
    		identifier[*iden_i] = *fp;
    		*iden_i=*iden_i+1;
    	}
    }
}