#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]){
	char buffer[BUFFER_SIZE], filename[64] = "Task3Input.txt";
	int buffer_i=0, ch;
	FILE *filePtr;

	filePtr = fopen(filename, "rb");
	if (filePtr == NULL){
        printf("Cannot open file \n");
        exit(0);
    }

    printf("The Words Starting with 'm' or 't' are\n\n");
    while ((ch = fgetc(filePtr)) != EOF){
		if (isalnum(ch))
			buffer[buffer_i++] = ch;
		else if((ch == ' ' || ch == '\n') && (buffer_i != 0)){
			buffer[buffer_i] = '\0';
			buffer_i = 0;
			if (buffer[0] == 't' || buffer[0] == 'm')
				printf("%s\n", buffer);
		}
	}

	fclose(filePtr);
	return 0;
}