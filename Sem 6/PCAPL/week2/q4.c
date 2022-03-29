#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int rank, size, num;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (rank == 0)
    {
        printf("\nEnter a number -- ");
        scanf("%d", &num);
        printf("\nProcess 0 -- ");
        printf("\nSending integer %d\n", num);
        MPI_Send(&num, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Recv(&num, 1, MPI_INT, size - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("\nProcess 0 -- \nReceived int %d\n", num);
    }
    else
    {
        MPI_Recv(&num, 1, MPI_INT, rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("\nProcess %d -- ", rank);
        printf("\nReceived integer %d", num);
        num++;
        printf("\nSending integer %d\n", num);
        MPI_Send(&num, 1, MPI_INT, (rank + 1) % size, 0, MPI_COMM_WORLD);
    }
    MPI_Finalize();
    return 0;
}