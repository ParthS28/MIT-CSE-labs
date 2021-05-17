#include<stdio.h>
#include <stdlib.h>
#include <math.h>
int** generatePowerSet(int arr[],int n,int** d){
    int m = pow(2,n) - 1;
    int** a = (int**)malloc(m* sizeof(int*));
    int* c = (int*)malloc(m*sizeof(int));
    for(int i=0;i<m;i++)
    {
    c[i] = 0;
    a[i] = (int*)malloc(sizeof(int)*n);
    }
    int s = 0;
    for(int i=1;i<m;i++){
    int k = 0;
    for(int j=0;j<n;j++){
    if(i & (1<<j)){
    a[s][k] = arr[j];
    k++;
    c[s] += arr[j];
    }
    }
    a[s][k] = -1;
    s++;
    }
    *d = c;
    return a;
}

void displayPower(int** a,int k,int n){
    int m = pow(2,n)-1;
    int s = 0;
    if(k == -1)
    {
    for(int i=0;i<m-1;i++){
    int j=0;
    while(a[i][j] != -1){
    printf("%d ",a[i][j]);
    j++;
    }
    printf("\n");
    }
    }
    else{
    int j=0;
    while(a[k][j] != -1){
    printf("%d ",a[k][j] );
    j++;
    }
    printf("\n");
    }
}

void partition(int** a, int n,int* c){
    int s = pow(2,n)-1;
    for(int i=0;i<s-1;i++){
        int d = c[i];
        for(int j=0;j<s-1;j++){
            if(i == j || c[j] == -1){
                continue;
            }
            if(d == c[j]){
                c[j] = -1;
                c[i] = -1;
                displayPower(a,i,n);
                displayPower(a,j,n);
            }
        }
    }
}

int main(int argc, char const *argv[]){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int* c;
    int** a = generatePowerSet(arr,n,&c);
    // printf("Power set: \n");
    // displayPower(a,-1,n);
    printf("Partitions: \n");
    partition(a,n,c);
    return 0;
}