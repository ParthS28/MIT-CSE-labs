#include<stdio.h>
#include<stdlib.h>

struct AdjListNode{
    int dest;
    struct AdjListNode* next;
};

struct AdjList{
    struct AdjListNode *head;
};

struct Graph{
    int V;
    struct AdjList* array;
};

struct AdjListNode* newAdjListNode(int dest){ 
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V){
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array =
    (struct AdjList*) malloc(V * sizeof(struct AdjList));
    int i;
    for (i = 0; i < V; ++i)
    graph->array[i].head = NULL;
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest){
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

void display(struct Graph* graph)
{
    int v;
    for (v = 0; v < graph->V; ++v){
        struct AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl){
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

int main()
{
    printf("Enter number of vertices-\n");
    int v, ch, s, d;
    scanf("%d",&v);
    struct Graph* graph = createGraph(v);
    ch == 0;
    while(ch != 3){
        printf("Enter 1) Add edge, 2) Display and 3) Exit\n"); 
        scanf("%d",&ch);
        if(ch == 1){
            printf("Enter source and destination-\n");
            scanf("%d%d",&s, &d); addEdge(graph, s, d);
        }
        else if(ch == 2)
            display(graph);
    }
} 