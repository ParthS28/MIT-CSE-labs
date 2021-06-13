#include <stdio.h>
#include <stdlib.h>
int opcount = 0;

int partition(int arr[], int l, int h){
    int pivot=arr[l];
    int i=l,j=h;
    while(i<j){
        opcount++;
        while(arr[i]<=pivot&&i<=j){
            i++;
        }
        while(arr[j]>=pivot&&j>=i){
            j--;
        }
        if(i<j){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int temp1=arr[l];
    arr[l]=arr[j];
    arr[j]=temp1;
    return j;
}

void QuickSort(int arr[],int i, int j){
    if(i<j){
        int pivot=partition(arr,i,j);
        QuickSort(arr,i,pivot);
        QuickSort(arr,pivot+1,j);
    }
}

void main(){
    int n,i,j;

    for(int i = 2; i < 10; i++){
        int arr[i];
        printf("Number: %d\n", i);
        for(int j = 0; j < i; j++){
            arr[j] = rand();
            printf("%d ", arr[j]);
        }
        printf("\nSorted: \n");
        QuickSort(arr, 0, i);
        for(int j = 0; j < i; j++){
            printf("%d ", arr[j]);
        }
        printf("\nOpcount: %d\n", opcount);
    }
    
    // printf("Enter number of elements: ");
    // scanf("%d",&n);
    // printf("Enter elements\n");
    // int arr[n];
    // for(i=0;i<n;i++){
    //     scanf("%d",&arr[i]);
    // }
    // QuickSort(arr, 0, n);
    // for(i=0;i<n;i++){
    //     printf("%d ",arr[i]);
    // }
    // printf("\nopcount: %d\n",opcount);
}