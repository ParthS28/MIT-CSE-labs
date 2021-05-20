#include <stdio.h>
#include <stdlib.h>
#define size 100

int g[size][size];
int n;
int visited[size];
int queue[size];
int front = 0, rear = 0;

void enqueue(int i){
    queue[rear++] = i;
}
int dequeue(){
    if(front == rear)
        return -1;
    return queue[front++];
}

void helper(int v){
    printf("%d, ", v);
    visited[v] = 1;

    for(int i = 0; i < n; i++){
        if(i!=v && visited[i] == 0 && g[v][i] == 1){
            enqueue(i);
            helper(i);
        }
    }
}

void bfs(){
    // enqueue first vertex
    enqueue(0);
    int x;
    do{
        x = dequeue();
        if(x != -1 && visited[x] == 0)
            helper(x);
        
    }while(x != -1);
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
    bfs();

}