// #include "mpi/mpi.h"
// #include <stdio.h>
// #define comm MPI_COMM_WORLD

// int main(){
//     int rank,size;
//     int arr[10],num;
//     MPI_Status status;
//     MPI_Init(NULL,NULL);
//     MPI_Comm_rank(comm,&rank);
//     MPI_Comm_size(comm,&size);
//     int buff[100];
//     int buffsize=100;

//     if(rank==0){
//         printf("enter an array of %d numbers",size-1);
//         for(int i=1;i<=size;i++){
//             scanf("%d",&arr[i]);
//         }
//         MPI_Buffer_attach(buff,buffsize);
//         for(int i=1;i<=size;i++){
//             MPI_Bsend(&arr[i],1,MPI_INT,i,i,comm);
//         }
//         MPI_Buffer_detach(&buff,&buffsize);
//     }
//     else{
//         MPI_Recv(&num,1,MPI_INT,0,rank,comm,&status);
//         if(rank%2==0){
//             printf("in rank %d and number received is %d\neven rank - squared number is %d\n\n",rank,num,num*num);

//         }
//         else{
//             printf("in rank %d and number received is %d\nodd rank - cubed number is %d\n\n",rank,num,num*num*num);

//         }

//     }
//     MPI_Finalize();
//     return 0;
// }

#include "mpi/mpi.h"
#include <stdio.h>
#define comm MPI_COMM_WORLD

int main(){
    int rank,size;
    int arr[10],num;
    MPI_Status status;
    MPI_Init(NULL,NULL);
    MPI_Comm_rank(comm,&rank);
    MPI_Comm_size(comm,&size);
    int buff[100];
    int buffsize=100;

    if(rank==0){
        printf("enter an array of %d numbers",size-1);
        for(int i=1;i<=size;i++){
            scanf("%d",&arr[i-1]);
        }
        MPI_Buffer_attach(buff,buffsize);
        for(int i=1;i<=size;i++){
            MPI_Bsend(&arr[i-1],1,MPI_INT,i,i,comm);
        }
        MPI_Buffer_detach(&buff,&buffsize);
    }
    else{
        MPI_Recv(&num,1,MPI_INT,0,rank,comm,&status);
        if(rank%2==0){
            printf("in rank %d and number received is %d\neven rank - squared number is %d\n\n",rank,num,num*num);

        }
        else{
            printf("in rank %d and number received is %d\nodd rank - cubed number is %d\n\n",rank,num,num*num*num);

        }

    }
    MPI_Finalize();
    return 0;
}

// #include <stdio.h>
// #include "mpi.h"
// #include <stdlib.h>
// int main(int argc, char *argv[])
// {
//     int rank;
//     int val = 0;
//     int size;
//     int arr[25];
//     MPI_Status status;
//     int b[25];
//     MPI_Init(&argc, &argv);
//     MPI_Buffer_attach(b, 25 * sizeof(int));
//     MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//     MPI_Comm_size(MPI_COMM_WORLD, &size);
//     if (rank == 0)
//     {
//         fprintf(stdout, "Input %d numbers: ", size - 1);
//         fflush(stdout);
//         for (int i = 1; i < size; i++)
//             scanf("%d", &arr[i - 1]);
//         for (int i = 1; i < size; i++)
//         {
//             MPI_Bsend(&arr[i - 1], 1, MPI_INT, i, i, MPI_COMM_WORLD);
//         }
//     }
//     else
//     {
//         MPI_Recv(&val, 1, MPI_INT, 0, rank, MPI_COMM_WORLD, &status);
//         if (rank % 2 == 0)
//         {
//             fprintf(stdout, "In process: %d, Squaring..\n Result: %d\n", rank, (val * val));
//             fflush(stdout);
//         }
//         else
//         {
//             fprintf(stdout, "In process: %d, Cubing..\n Result: %d\n", rank, (val * val * val));
//             fflush(stdout);
//         }
//     }
//     MPI_Finalize();
//     return 0;
// }