// Implement a C program to read, display and to find the product of two matrices using functions  with  suitable  parameters. 
// Note  that  the  matrices  should  be  created  using dynamic  memory  allocation functions  and  the  elements  are  accessed  using  array dereferencing. 

#include <stdlib.h>
#include <stdio.h>

void matmul(int a[][100], int b[][100], int ans[][100], int r1, int c1, int r2, int c2){
	for(int i = 0; i < r1; i++){   // Initialise ans to 0
		for(int j = 0; j < c2; j++){
			ans[i][j] = 0;
		}
	}

	for(int i = 0; i < r1; i++){   
		for(int j = 0; j < c2; j++){
			for(int k = 0; k < c1; k++){
				ans[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}

int main(){
	int r1, c1, r2, c2;
	int a[100][100], b[100][100], ans[100][100];
	printf("Enter dimensions of first matrix\n");
	scanf("%d %d", &r1, &c1);
	printf("Enter dimensions of second matrix\n");
	scanf("%d %d", &r2, &c2);
	if(c1 != r2){
		printf("Invalid operation\n"); return 0;
	}
	printf("Enter elements:\n");
	for(int i = 0; i < r1; i++)
		for(int j = 0; j < c1; j++)
			scanf("%d", &a[i][j]);

	printf("Enter elements:\n");
	for(int i = 0; i < r2; i++)
		for(int j = 0; j < c2; j++)
			scanf("%d", &b[i][j]);
	matmul(a, b, ans, r1, c1, r2, c2);
	for(int i = 0; i < r1; i++){   
		for(int j = 0; j < c2; j++){
			printf("%d  ", ans[i][j]);
		}
		printf("\n");
	}
	// int ** a = (int **)calloc(r1+1, sizeof(int *));
	// int ** b = (int **)calloc(r2+1, sizeof(int *));
	// for(int i = 0; i < r1; i++){
	// 	// table[i] = (int *) calloc(colNum+1, sizeof(int));
	// 	a[i] = (int *) calloc(c1+1, sizeof(int));
	// 	for(int j = 0; j < c1; j++){
	// 		scanf("%d", &a[i][j]);
	// 	}
	// }

	return 0;
}