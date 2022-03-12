#include<mpi.h>
#include<stdio.h>
#include<math.h>
int main(int argc,char* argv[]){

	int rank,size;
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);

	int x=5;
	

	int result=pow(x,rank);
    printf("pow(x,rank) for process %d is %d \n",rank,result);

	MPI_Finalize();
	return 0;	
}