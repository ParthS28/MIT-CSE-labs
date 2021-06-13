#include <stdio.h>
#include <stdlib.h>
#define size 100

int g[size][size];
int visited[size];
int n;
int stack[size];
int s = -1;

void dfs(int v){
    visited[v] = 1;
    stack[s++] = v;
    for(int i = 0; i < n; i++){
        if(g[v][i] == 1 && visited[i] == 0 && i != v){
            dfs(i);
        }
    }

    
}

void printStack(){
    for(int i = n-1; i >=0; i--){
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main()
{
	printf("Enter the Number of Vertices : \n");
	scanf("%d", &n);
	
	printf("Enter the Adjacency Matrix : \n");
	
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<n; j++)
		{
    		scanf("%d", &g[i][j]);
		}
	}

	for(int i = 0; i<n; i++)
	{
		if(!visited[i])
		{
    		dfs(i);
		}
	}

	printf("The Topological Sort Order is :\n");
	printStack();
	

	return 0;
}