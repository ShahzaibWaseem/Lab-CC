#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define STRING_SIZE 10

void IsValid(char input[]);

int main(int argc, char const *argv[]){
	char input[STRING_SIZE];

	printf("Enter a line: ");
	scanf("%s", input);

	IsValid(input);
	return 0;
}

void IsValid(char input[]){
	char character;
	bool valid = false;
	for (int i = 1; i < strlen(input); ++i){

		if((input[0] >= 'a' && input[0] <= 'z') || (input[0] >= 'A' && input[0] <= 'Z')){
	        // VALID: First character is an alphabet
	        character = input[i];
	        if ( !(((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z')) || (character >= '0' && character <= '9')) ){
	        	if (character == '_')
	        		valid = true;
	        	else{
	        		valid = false;
	        		break;
	        	}
	        }
	        else{
	        	valid = true;
	        }
	    }
	    else{
	    	valid = false;
	    	break;
	    }
	}
	printf(valid ? "Is Valid\n" : "Is InValid\n");
}