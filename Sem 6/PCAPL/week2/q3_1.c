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
        for(int i=1;i<size;i++){
            scanf("%d",&arr[i]);
        }
        MPI_Buffer_attach(buff,buffsize);
        for(int i=1;i<size;i++){
            MPI_Bsend(&arr[i],1,MPI_INT,i,i,comm);
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