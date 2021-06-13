#include <stdio.h>
#include <stdlib.h>

int opcount = 0;

void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        opcount++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        opcount++;
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        opcount++;
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r){
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}

void main(){
    int n;

    for(int i = 2; i < 10; i++){
        int arr[i];
        printf("Number: %d\n", i);
        for(int j = 0; j < i; j++){
            arr[j] = rand();
            printf("%d ", arr[j]);
        }
        printf("\nSorted: \n");
        mergeSort(arr, 0, i-1);
        for(int j = 0; j < i; j++){
            printf("%d ", arr[j]);
        }
        printf("\nOpcount: %d\n", opcount);
    }
}