#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    int size, rank;
    MPI_Status status;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    char word[5], y[5];
    int len = 5 * sizeof(char);
    if (rank == 0)
    {
        scanf("%s", word);
        MPI_Ssend(word, len, MPI_CHAR, 1, 101, MPI_COMM_WORLD);
        printf("Process %d sent: %s\n", rank, word);
        MPI_Recv(word, len, MPI_CHAR, 1, 102, MPI_COMM_WORLD,
                 &status);
        printf("Process %d received: %s\n", rank, word);
    }
    else
    {
        MPI_Recv(y, len, MPI_CHAR, 0, 101, MPI_COMM_WORLD,
                 &status);
        printf("Process %d received: %s\n", rank, y);
        for (int i = 0; i < strlen(y); i++)
        {
            if (y[i] >= 'A' && y[i] <= 'Z')
                y[i] += 32;
            else if (y[i] >= 'a' && y[i] <= 'z')
                y[i] -= 32;
        }
        sleep(1);
        MPI_Ssend(y, len, MPI_CHAR, 0, 102, MPI_COMM_WORLD);
        printf("Process %d sent: %s\n", rank, y);
    }
    MPI_Finalize();
}