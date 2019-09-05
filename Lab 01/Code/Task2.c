#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void addition(int,int);
void subtraction(int,int);
void multiplication(int,int);
void division(int,int);
void modulus(int,int);
void power(int,int);
void factorial(int);
void operations();

int main(int argc, char const *argv[]){
	int number1, number2;
	char operation;

	// number input
	printf("Enter Number 1: ");
	scanf("%d", &number1);
	printf("Enter Number 2: ");
	scanf("%d", &number2);

	while(1){
		operations();
		printf("What operations do you want to perform: ");
		scanf(" %c", &operation);

		switch(operation){
			case 'a': addition(number1, number2);break;
			case 's': subtraction(number1, number2);break;
			case 'm': multiplication(number1, number2);break;
			case 'd': division(number1, number2);break;
			case '?': modulus(number1, number2);break;
			case '^': power(number1, number2);break;
			case '!': factorial(number1);break;
			case 'q': exit(0);break;
			case 'c': system("clear");break;	// use system("cls") for Windows
			default: system("clear");
				printf("Option not available\nTry Again");
		}
	}
	return 0;
}

void addition(int number1, int number2){
	printf("The sum of the two numbers is: %d\n", number1+number2);
}

void subtraction(int number1, int number2){
	printf("The difference of the two numbers is (number1 - number2): %d\n", number1-number2);
}

void multiplication(int number1, int number2){
	printf("The product of the two numbers is: %d\n", number1*number2);
}

void division(int number1, int number2){
	printf("The division of number1 with number2 is: %f\n", (float) number1 / (float) number2);
}

void modulus(int number1, int number2){
	printf("The modulus of number1 with number2 is: %d\n", number1%number2);
}

void power(int base, int exponent){
	printf("The base raised to the exponent is: %lf\n", pow((double) base, (double) exponent));
}

void factorial(int number){
	int i;
	unsigned long long factorial = 1;
	if (number < 0)
        printf("Error! Factorial of a negative number doesn't exist.");
    else{
        for(i=1; i <= number; ++i){
            factorial *= i;
        }
        printf("Factorial of %d = %llu\n", number, factorial);
    }
}

void operations(){
	printf("Press c to clear the screen\n");
	printf("Press q to quit\n");
	printf("a - addition\ns - subtraction\nm - multiplication\nd - division\n? - modulus\n^ - power\n! - factorial\n");
}