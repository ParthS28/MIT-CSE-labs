#include <stdio.h>

int add(int a, int b){
    return a+b;
}

int main(){
    int a = 1; 
    double buf;
    if(a % 2 == 1){  // Check if odd
        printf("Odd\n");
    }
    else{  // Else it is even
        printf("Even\n");
    }
    return 0;
}