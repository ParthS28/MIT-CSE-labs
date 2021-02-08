// Write a function Smallest to find the smallest element in an array using pointer.
// Create a dynamically allocated array and read the values from keyboard in main.
// Display the result in the main function.

#include <stdlib.h>
#include <stdio.h>

int Smallest(int *p, int n){
	int min = 999999;
	for(int i = 0; i < n; i++){
		if(min > *(p+i)){
			min = *(p+i);
		}
	}
	return min;
}

int main(){
	int n;
	printf("Enter size: ");
	scanf("%d", &n);
	// printf("%d\n", n);
	int* arr;
	arr = malloc(n*sizeof(int));
	printf("Enter elements\n");
	for(int i =0; i < n; i++){
		scanf("%d", arr+i);
	}
	int ans = Smallest(arr, n);
	printf("Smallest = %d\n", ans);
	// for(int i = 0; i < n; i++){
	// 	printf("%d\n", *arr+i);
	// }
	free(arr);
	return 0;
}
