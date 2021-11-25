// even odd sum

// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>

// void* even_sum(void* param){
//     int* arr = (int *)param;
//     int n = arr[0];
//     int sum = 0;
//     for(int i = 1; i <= n; i++){
//         if((i-1) % 2 == 0) 
//             sum += arr[i];
//     }
//     arr[n+1] = sum;
//     return NULL;
// }

// void* odd_sum(void* param){
//     int* arr = (int *)param;
//     int n = arr[0];
//     int sum = 0;
//     for(int i = 1; i <= n; i++){
//         if((i-1) % 2 == 1) 
//             sum += arr[i];
//     }
//     arr[n+2] = sum;
//     return NULL;
// }

// int main(int argc, char* argv[]){
//     int n;
//     printf("Enter the number of terms\n");
//     scanf("%d", &n);

//     int arr[100];
//     for(int i = 0; i <= n+1; i++){
//         arr[i] = 0;
//     }
//     arr[0] = n;
//     printf("Enter terms\n");
//     for(int i = 1; i <= n; i++){
//         scanf("%d", &arr[i]);
//     }

//     pthread_t thread;
//     pthread_create(&thread, 0, &calc, (void *)arr);
//     pthread_join(thread, 0);

//     printf("Sum = %d\n", arr[n+1]);
//     return 0;
// }



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
 
volatile int running_threads = 0;
pthread_t thread[1];
int numOfElements;
int evensum, oddsum;

void *findsum(void *array_ptr){ 
    int i;	 
    
    int *arr = (int*)array_ptr;
    for(i = 0; i < numOfElements; i++){
        if(arr[i]%2==0)
            evensum += arr[i];
        else
            oddsum += arr[i];
    }
    
    running_threads -= 1;
    
    return NULL;
}
 
int getArrayInput(int n, int *arr_ptr){
    int input;
    int numberOfElements = 0;
 
   	printf("Enter numbers\n");
    
    while(1){
        printf("Enter a positive value(Negative Number to Stop):\n");

        if(scanf("%d",&input) != 1){
            printf("Invalid\n");
            exit(1);
        }
 
    	if(input >= 0){
    		if (numberOfElements == n){
    			n += 1;
    			arr_ptr = realloc(arr_ptr, n * sizeof(int));
       		}
 
        	arr_ptr[numberOfElements++] = input;
        } 
 
        else{
        	printf("\nNumber of Integers: %d\n", numberOfElements);
        	break;
        }
    }
 
    return numberOfElements;
}
 
 
void createThreads(int *arr_ptr){
    int s;
    s = pthread_create(&thread[2], NULL, findsum, (void *)arr_ptr);

    running_threads += 1;
}
 
int main(){
    int n = 1;
    int *arr_ptr = malloc(n * sizeof(int));
    numOfElements = getArrayInput(n, arr_ptr);
    
    createThreads(arr_ptr);
    
    while(running_threads>0){
        sleep(1);
    }

    printf("\nThe sum of even numbers = %d\nThe sum of odd numbers = %d\n", evensum, oddsum);
    return(0);
}
