#include <stdio.h>

#define STRING_SIZE 10

int size=0;

void push(int [], int);
int pop(int []);
void viewStack(int []);

int main(int argc, char const *argv[]){
	int array[STRING_SIZE];
	push(array, 1);
	push(array, 2);
	push(array, 3);
	push(array, 4);
	push(array, 5);
	push(array, 6);
	push(array, 7);
	push(array, 8);
	push(array, 9);
	viewStack(array);
	push(array, 10);
	viewStack(array);
	push(array, 11);
	viewStack(array);
	push(array, 12);

	viewStack(array);
	int temp = pop(array);
	viewStack(array);
	printf("The Number Poped is: %d\n", temp);

	return 0;
}

void push(int *array, int newNumber){
	if (size >= STRING_SIZE){
		printf("Stack Size Exceded (Number not added)\n");
		return;
	}
	array[size++] = newNumber;
}

int pop(int array[]){
	if(size==0){
		printf("Invalid Operation (Stack already empty)\n");
		return;
	}
	return array[--size];
}

void viewStack(int *array){
	printf("The Contents of the Stack are:\t");
	for (int i = 0; i < sizeof(array)/sizeof(int) || i < size; ++i)
		printf("%d ", array[i]);
	printf("\n");
}