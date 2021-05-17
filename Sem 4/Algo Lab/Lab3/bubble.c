#include<stdio.h>
#include<stdlib.h>
void bubbleSort(int *a, unsigned int n)
{
    unsigned int i,j,min;
    int temp, flag = 0;
    int opcount=0; // introduce opcount
    for(i= 0; i<n; i++){
        for(j=0; j<n-i-1; j++){
            ++opcount; // increment opcount for every comparison
            if(a[j+1] < a[j]){
                ++opcount;
                flag = 1;
                temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
            }
        }
        if(flag == 0)
            break;
    }
    printf("\nOperation Count %d\n",opcount);
}

int main(){
    int *a;
    int i, n = 5;
    // generate worst case input of different input size
    for (int j=0; j < 6; j++){
        a = (int *)malloc(sizeof(int)*n);
        for (int k=0; k< n; k++)
            a[k] = n-k; // descending order list
        printf("Elements are: ");
        for(i=0;i<n;i++)
            printf("%d ",a[i]);
        bubbleSort(a, n);
        printf("Elements after bubble sort: ");
        for(i = 0; i < n; i++)
            printf("%d ",a[i]);
        printf("\n");
        free(a);
        n = n + 5; // try with a new input size
    }
    return 0;
}