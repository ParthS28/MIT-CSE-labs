#include <mpi.h>
#include <stdio.h>
#include <math.h>
int main(int argc, char **argv)
{
    MPI_Init(NULL, NULL);
    int size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int A[100], m = 3;
    float B[100];
    if (rank == 0)
    {
        printf("Enter M: ");
        scanf(" %d" , &m);
        printf("Enter %d size array: \n", size * m);
        for (int i = 0; i < size * m; i++)
        {
            scanf(" %d", &A[i]);
        }
    }
    int c[m];
    float avg = 0;
    MPI_Scatter(A , m ,MPI_INT, &c , m, MPI_INT, 0 , MPI_COMM_WORLD);

    for(int i = 0; i < m; i++){
        avg+=c[i];
    }
    avg/=m;
    printf("Process %d outputs %.1f\n" , rank , avg);
    MPI_Gather(&avg , 1 ,MPI_FLOAT, B , 1, MPI_FLOAT, 0 ,
    MPI_COMM_WORLD);
    if(rank==0){
        float tavg = 0;
        for(int i = 0; i < size; i++){
            tavg += B[i];
        }
        tavg /= size;
        printf("The total average is : %.1f\n" , tavg);
    }
    MPI_Finalize();
}