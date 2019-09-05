#include <stdio.h>

void digitAdder(int num){
	int sum=0, remainder;
	while(num != 0){
		remainder = num % 10;
		sum += remainder;
		num /= 10;
	}
	printf("The Sum of Digits is : %d\n", sum);
}

int main(int argc, char const *argv[]){
	int num = -1;
	while(num >= 1000 || num < 0){
		printf("Please Enter a positive number under 1000: ");
		scanf("%d", &num);
	}
	digitAdder(num);
	return 0;
}