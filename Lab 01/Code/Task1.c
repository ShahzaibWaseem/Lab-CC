#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define STRING_LIMIT 20

// Identify whether a given line is a comment or not
bool isComment(char* string){
	if(string[0] == '/' && string[1] == '/')
		return true;
	else if (string[0]=='/' && string[1]=='*' && string[strlen(string)-2]=='*' && string[strlen(string)-1]=='/')
		return true;
	else
		return false;
}

int main(int argc, char const *argv[]){
	char string[STRING_LIMIT];
	printf("Pass the String: ");
	scanf("%s", string);
	printf("Is the string a comment?: ");
	printf(isComment(string) ? "true\n" : "false\n");
	return 0;
}