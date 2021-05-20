#include <stdio.h>
#include <stdlib.h>
#define size 100

int g[size][size];
int visited[size];
int n;
int stack[size];
int s = -1;

void push(int x){
    printf("Pushing %d\n", x);
    stack[++s] = x;
}
int pop(){
    if(s == -1){
        printf("Empty\n");
        return -1;
    }
    int x = stack[s--];
    printf("Popping %d\n", x);
    return x;
}

void helper(int v){
    
}

void dfs(){
    // push first
    push(0);
    visited[0] = 1;

    int cur = pop();
    do{
        for(int i = 0; i < n; i++){
            if(g[cur][i] == 1 && visited[i] == 0 && i != cur){
                push(i);
            }
        }
        printf("Visiting %d\n", cur);
        visited[cur] = 1;
        cur = pop();
    }while(cur != -1);
}

int main(){
    
    printf("Enter number of vertices\n");
    scanf("%d", &n);

    printf("Enter adjacency matrix\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &g[i][j]);
        }
    }

    for(int i = 0; i < n; i++){
        visited[i] = 0;
    }
    dfs();

}
