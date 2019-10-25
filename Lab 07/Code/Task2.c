#include <stdio.h>

#define STRING_SIZE 10

int size=0;

void queue(int [], int);
int dequeue(int []);
void viewQueue(int []);

int main(int argc, char const *argv[]){
	int array[STRING_SIZE];
	dequeue(array);

	queue(array, 1);
	queue(array, 2);
	queue(array, 3);
	queue(array, 4);
	queue(array, 5);
	queue(array, 6);
	queue(array, 7);
	queue(array, 8);
	queue(array, 9);
	viewQueue(array);
	queue(array, 10);
	viewQueue(array);
	queue(array, 11);
	viewQueue(array);
	queue(array, 12);

	viewQueue(array);
	int temp = dequeue(array);
	viewQueue(array);
	printf("The Number deQueued is: %d\n", temp);

	return 0;
}

void queue(int array[], int newNumber){
	if (size >= STRING_SIZE){
		printf("Queue Size Exceded (Number not added)\n");
		return;
	}
	array[size++] = newNumber;
}
int dequeue(int array[]){
	if(size==0){
		printf("Invalid Operation (Queue already empty)\n");
		return;
	}
	int temp=array[0];
	for (int i = 0; i < size; ++i)
		array[i] = array[i+1];
	size--;
	return temp;
}

void viewQueue(int *array){
	printf("The Contents of the Queue are:\t");
	for (int i = 0; i < sizeof(array)/sizeof(int) || i < size; ++i)
		printf("%d ", array[i]);
	printf("\n");
}