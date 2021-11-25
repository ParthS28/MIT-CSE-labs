// prime numbers

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int isprime(int n){
    for(int i = 2; i < n; i++){
        if(n % i == 0){
            // not prime
            return 0;
        }
    }
    return 1;
}

void* prime(void* param){
    int* arr = (int *)param;
    int count=0;
    int start = arr[0];
    int end = arr[1];
    for(int i = start; i <= end; i++){
        if(isprime(i) == 1){
            arr[3+count] = i;
            count++;
        }
    }
    arr[2] = count;
    return NULL;
}

int main(int argc, char * argv[]){
    
    int arr[100];
    for(int i = 0; i <= 100; i++){
        arr[i] = 0;
    }
    
    printf("Enter start and end\n");
    scanf("%d %d", &arr[0], &arr[1]);

    pthread_t thread;
    pthread_create(&thread, 0, &prime, (void *)arr);
    pthread_join(thread, 0);
    printf("Prime numbers are\n");
    int count = arr[2];
    for(int i = 0; i < count; i++){
        printf("%d ", arr[3+i]);
    }
    printf("\n");
    return 0;
}