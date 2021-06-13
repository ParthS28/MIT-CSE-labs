#include <stdio.h>
#include <stdlib.h>

int queue[100], f = 0, r = 0, arr[100][100], n, indegree[100];

void calc_indegree(){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(arr[j][i] && i!=j)
                indegree[i]++;
        }
    }
}

void decrease(int v){
    for(int i = 0; i<n; i++){
        if(arr[v][i]){
            indegree[i]--;
            if(indegree[i] == 0)
                queue[r++] = i;
        }
    }
}

int queueEmpty(){
    for(int i = 0; i<n; i++){
        if(queue[i] != -1)
            return 0;
    }
    return 1;
}

void main()
{
    printf("Enter the Number of Vertices : \n");
    scanf("%d", &n);

    printf("Enter the Adjacency Matrix : \n");
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++)
            scanf("%d", &arr[i][j]);
    }

    for(int i = 0; i<n; i++)
        queue[i] = -1;
    calc_indegree();

    for(int i = 0; i<n; i++){
        if(indegree[i] == 0)
            queue[r++] = i;
    }
    printf("The Topological Sort Order is : \n");
    while(!queueEmpty()){
        int vertex = queue[f++];
        queue[f-1] = -1;
        decrease(vertex);
        printf("%d ", vertex);
    }
    printf("\n");
}


// #include <stdio.h>
// #include <stdlib.h>
// #define size 100

// int g[size][size];
// int n;
// int queue[size];
// int f = -1, r = -1;

// void push(int x){
//     if(f == -1 && r == -1){
//         queue[0] = x;
//         f = 0;
//         r = 0;
//         return;
//     }
//     queue[++r] = x;
//     // printf("queue: ");
//     // for(int i = f; i <=r; i++){
//     //     printf("%d ", queue[i]);
//     // }
// }

// int pop(){
//     if(f == -1){
//         printf("Empty");
//     }
//     return queue[f++];
// }

// void topo(){
//     int indegree[n];
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < n; j++){
//             if(i == j) continue;
//             if(g[j][i] == 1) indegree[i]++;
//         }
//     }

//     for(int i = 0; i < n; i++){
//         if(indegree[i] == 0)
//             push(i);
//     }

//     int order[n], cur = 0;

//     while(1){
//         int u = pop();
//         order[cur++] = u;
//         // printf("%d ", u);
//         for(int i = 0; i < n; i++){
//             if(g[i][u]==1 && u != i){
//                 indegree[i]--;
//                 if(indegree[i] == 0)
//                     push(i);
//             }
//         }
//         if(cur == n) break;
//     }

//     for(int i = 0; i < n; i++){
//         printf("%d ", order[i]);
//     }
//     printf("\n");
// }
// int main(){
//     printf("Enter the Number of Vertices : \n");
// 	scanf("%d", &n);
	
// 	printf("Enter the Adjacency Matrix : \n");
	
// 	for(int i = 0; i<n; i++)
// 	{
// 		for(int j = 0; j<n; j++)
// 		{
//     		scanf("%d", &g[i][j]);
// 		}
// 	}

//     topo();
// }
