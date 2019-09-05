#include <stdio.h>

int main(int argc, char const *argv[]){
	int mat1_r, mat1_c, mat2_r, mat2_c;
	int i, j, k, sum;
	int matrix1[10][10], matrix2[10][10], mulMatrix[10][10];

	printf("Enter number of rows and columns of first matrix: ");
	scanf("%d%d", &mat1_r, &mat1_c);
	printf("Enter elements of first matrix\n");

	// input matrix 1
	for (i = 0; i < mat1_r; i++)
		for (j = 0; j < mat1_c; j++)
			scanf("%d", &matrix1[i][j]);

	printf("Enter number of rows and columns of second matrix: ");
	scanf("%d%d", &mat2_r, &mat2_c);

	if (mat1_c != mat2_r)
		printf("The matrices can't be multiplied with each other.\n");
	else{
		printf("Enter elements of second matrix\n");
		// input matrix 2
		for (i = 0; i < mat2_r; i++)
			for (j = 0; j < mat2_c; j++)
				scanf("%d", &matrix2[i][j]);

		// initialization result matrix
		for (i = 0; i < mat1_r; i++)
			for (j = 0; j < mat2_c; j++)
				mulMatrix[i][j] = 0;

		// multiplication
		for (i = 0; i < mat1_r; i++)
			for (j = 0; j < mat2_c; j++)
				for (k = 0; k < mat1_c; k++)
					mulMatrix[i][j] += matrix1[i][k]*matrix2[k][j];

		// printing multiplied matrix
		printf("The multiplied Matix is:\n");
		for (i = 0; i < mat1_r; i++){
			for (j = 0; j < mat2_c; j++)
				printf("%d\t", mulMatrix[i][j]);
			printf("\n");
		}
	}

	return 0;
}