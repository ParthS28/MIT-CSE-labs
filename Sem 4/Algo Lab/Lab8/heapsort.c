#include <stdio.h>
#include <stdlib.h>

int opcount = 0;

void heapify(int h[], int l, int n)
{
    int i, k, v, heapify, j;
    for(i = (n/2); i>=l; i--)
    {
        k = i; v = h[k]; heapify = 0;
        while(heapify == 0 && 2*k <= n)
        {
            j = 2*k;
            opcount++;
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

void HeapSort(int arr[], int n)
{
    int k = 0;
    for(int i = 1; i<+n; i++)
    {
        heapify(arr, 1, n - k);
        int temp = arr[1];
        arr[1] = arr[n-k];
        arr[n-k] = temp;
        k++;
    }
}

int main(){

    int n;

    for(int i = 2; i < 15; i++){
        printf("%d\n", i);
        n = i;
        int h[n];
        for(int j = 1; j <= n; j++){
            printf("%d ", j);
            h[j] = j;
        }
        HeapSort(h, n);
        printf("\n");
        printf("Heapified array:\n");
    
        for(int j = 1; j<=n; j++)
            printf("%d ", h[j]);

        printf("\n");
        printf("opcount = %d\n", opcount);
        opcount = 0;
    }

    return 0;
}


// #include <stdio.h>
// #include <stdlib.h>
// int opcnt = 0;
// void heapify(int heap[], int l, int n)
// {
//     int i, k, v, heapify, j;
//     for(i = (n/2); i>=l; i--)
//     {
//         k = i; v = heap[k]; heapify = 0;
//         while(heapify == 0 && 2*k <= n)
//         {
//             j = 2*k;
// 	        opcnt++;
//             if(j<n)
//                 if(heap[j]<heap[j+1])
//                     j = j+1;
//             if(v>=heap[j])
//                 heapify = 1;
//             else
//             {
//                 heap[k] = heap[j];
//                 k = j;
//             }
//         }
//         heap[k] = v;
//     }
// }
// void HeapSort(int arr[], int n)
// {
//     int j = 0;
//     for(int i = 1; i<=n; i++)
//     {
//         heapify(arr, 1, n - j);
//         int temp = arr[1];
//         arr[1] = arr[n-j];
//         arr[n-j] = temp;
//         j++;
//     }
// }
// void main()
// {
//         int n;

//     for(int i = 2; i < 15; i++){
//         opc
//         printf("%d\n", i);
//         n = i;
//         int h[n];
//         for(int j = 1; j <= n; j++){
//             printf("%d ", j);
//             h[j] = j;
//         }
//         HeapSort(h, n);
//         printf("\n");
//         printf("Heapified array:\n");
    
//         for(int j = 1; j<=n; j++)
//             printf("%d ", h[j]);

//         printf("\n");
//         printf("opcount = %d\n", opcnt);
//     }
//     // int n;
//     // printf("Enter the Number of Elements : \n");
//     // scanf("%d", &n);
//     // int arr[n+1];
//     // printf("Enter the Elements : \n");
//     // for(int i = 1; i<=n; i++)
//     //     scanf("%d", &arr[i]);
//     // HeapSort(arr, n);
//     // printf("The Sorted List is : \n");
//     // for(int i = 1; i<=n; i++)
//     //     printf("%d ", arr[i]);
//     // printf("\n");
//     // printf("OpCount = %d\n", opcnt);
// }