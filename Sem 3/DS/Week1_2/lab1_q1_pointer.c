#include <stdlib.h>
#include <stdio.h>

void matmul(int ** a, int ** b, int ** ans, int r1, int c1, int r2, int c2){
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
	printf("Enter dimensions of first matrix\n");
	scanf("%d %d", &r1, &c1);
	printf("Enter dimensions of second matrix\n");
	scanf("%d %d", &r2, &c2);
	if(c1 != r2){
		printf("Invalid operation\n"); return 0;
	}
	int ** a = (int **)calloc(r1+1, sizeof(int *));
	int ** b = (int **)calloc(r2+1, sizeof(int *));
	printf("Enter elements of a:\n");
	for(int i = 0; i < r1; i++){
		// table[i] = (int *) calloc(colNum+1, sizeof(int));
		a[i] = (int *) calloc(c1+1, sizeof(int));
		for(int j = 0; j < c1; j++){
			scanf("%d", &a[i][j]);
		}
	}
	printf("Enter elements of b:\n");
	for(int i = 0; i < r2; i++){
		// table[i] = (int *) calloc(colNum+1, sizeof(int));
		b[i] = (int *) calloc(c2+1, sizeof(int));
		for(int j = 0; j < c2; j++){
			scanf("%d", &b[i][j]);
		}
	}
	int ** ans = (int **)calloc(r1+1, sizeof(int *));
	for(int i = 0; i < r1; i++){
		ans[i] = (int *) calloc(c2+1, sizeof(int));
		for(int j = 0; j < c2; j++){
			ans[i][j] = 0;
		}
	}
	matmul(a, b, ans, r1, c1, r2, c2);
	printf("Answer:\n");
	for(int i = 0; i < r1; i++){
		
		for(int j = 0; j < c1; j++){
			printf("%d ", ans[i][j]);
		}
	printf("\n");
	}

	for(int i = 0; i < r1; i++){
		free(a[i]);
	}
	free(a);
	for(int i = 0; i < r2; i++){
		free(b[i]);
	}
	free(b);
	for(int i = 0; i < r1; i++){
		free(ans[i]);
	}
	free(ans);
	return 0;
}