#include <stdio.h>

int main(int argc, char const *argv[]){
	char operator;

	printf("Enter a statement: ");
	scanf("%c", &operator);

	switch(operator){
		case '*':
			printf("Multiplication\n");
			break;
		case '+':
			printf("Addition\n");
			break;
		case '-':
			printf("Subtraction\n");
			break;
		case '/':
			printf("Division\n");
			break;
		case '%':
			printf("Modulus\n");
			break;
		default:
			printf("Not an Operator\n");
	}
	return 0;
}