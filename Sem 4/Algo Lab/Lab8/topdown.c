#include <stdio.h>
#include <stdlib.h>

int opcount = 0;

void topDown(int arr[], int currIndex){
    int parent = (currIndex - 1) / 2;
    while(parent >= 0){
        opcount++;
        if(arr[parent]<arr[currIndex]){
            int temp = arr[parent];
            arr[parent] = arr[currIndex];
            arr[currIndex] = temp;

            currIndex = parent;
            parent = (currIndex - 1)/2;
        }
        else
            return;
    }
}

int main(){
    int n;

    for(int i = 2; i < 10; i++){
        printf("%d\n", i);
        n = i;
        int h[n];
        for(int j = 0; j < n; j++){
            printf("%d ", j+1);
            h[j] = j+1;
            topDown(h, j);
        }
        printf("\n");
        printf("Heapified array:\n");
    
        for(int j = 0; j<n; j++)
            printf("%d ", h[j]);

        printf("\n");
        printf("opcount = %d\n", opcount);
    }

    return 0;
}