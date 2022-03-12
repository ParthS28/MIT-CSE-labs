#include<mpi.h>
#include<stdio.h>

int main(int argc,char* argv[])
{
	int rank,size;
	int num1=30;
	int num2=9;
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);

   if(rank==0){
   	int sum=num1+num2;
   	printf("Process %d: SUM of %d and %d is %d \n",rank,num1,num2,sum);
   }
   else if(rank==1){
   	int diff=num1-num2;
   	printf("Process %d: DIFFERENCE of %d and %d is %d \n",rank,num1,num2,diff);
   }
   else if(rank==2){
   	int mul=num1*num2;
   	printf("Process %d: PRODUCT of %d and %d is %d \n",rank,num1,num2,mul);
   }
   else if(rank==3){
   	float quot=num1/num2;
   	printf("Process %d: QUOTIENT of %d and %d is %f \n",rank,num1,num2,quot);
   }
	MPI_Finalize();
	return 0;
}