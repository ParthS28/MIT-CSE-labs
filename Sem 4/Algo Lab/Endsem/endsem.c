#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

void heapify(int h[], int l, int n)
{
    int i, k, v, heapify, j;
    for(i = (n/2); i>=l; i--)
    {
        k = i; v = h[k]; heapify = 0;
        while(heapify == 0 && 2*k <= n)
        {
            j = 2*k;
            if(j<n)
                if(h[j]<h[j+1])
                    j = j+1;
            if(v>=h[j])
                heapify = 1;
            else
            {
                h[k] = h[j];
                k = j;
            }
        }
        h[k] = v;
    }
    return;
}

void display(int h[], int size){
    for(int i = 1; i <= size; i++){
        printf("%d ", h[i]);
    }
}

int searchIndex(int h[], int size, int e){
    int cur = 1;
    while(cur <= size){
        if(h[cur] == e)
            return cur;
        if(h[cur] < e) return -1;

        {
            for(int j = 0; j < 2*cur; j++){
                if(h[2*cur + j] == e){
                    return 2*cur + j;
                }
            }
        }
        cur = 2*cur;
    }
    return -1;
}

void deleteElement(int h[], int size, int index){
    for(int i = index; i < size+1; i++){
        h[i] = h[i+1];
    }
    heapify(h, 1, size);
}

int main(){
    int heap[SIZE];
    int ch = 0;
    int size = 0, n, max, ele;
    do
    {
        printf("Menu\n1.Insert\n2.Delete Maximum\n3.Delete element\n4.Display\n5.Exit\n");
        scanf("%d", &ch);

        switch(ch){
            case 1:
            printf("Enter element\n");
            scanf("%d", &n);
            size++;
            heap[size] = n;
            heapify(heap, 1, size);
            break;
            case 2:
            max = heap[1];
            printf("Maximum element: %d \n", max);
            heap[1] = heap[size];
            size--;
            heapify(heap, 1, size);
            break;
            case 3:
            printf("Enter element to be deleted\n");
            scanf("%d", &ele);
            int index = searchIndex(heap, size, ele);
            if(index == -1){
                printf("Not found\n");
                break;
            }
            printf("Found at %d\n", index);
            size--;
            deleteElement(heap, size, index);
            // size--;
            break;
            case 4:
            display(heap, size);
            break;
            default:
            printf("Wrong input\n");
        }
    } while (ch != 5);
    
}