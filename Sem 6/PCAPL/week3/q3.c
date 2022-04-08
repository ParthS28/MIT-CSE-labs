#include <mpi.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int rank, size;
    int count = 0;
    int b[100] = {0};
    int i, n, l;
    char str[100], c[100];
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (rank == 0)
    {
        n = size;
        printf("Enter the string: ");
        scanf("%s", str);
        l = strlen(str) / n;
    }
    MPI_Bcast(&l, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Scatter(str, l, MPI_CHAR, c, l, MPI_CHAR, 0, MPI_COMM_WORLD);
    count = 0;
    for (i = 0; i < l; ++i)
    {
        if (c[i] == 'a' || c[i] == 'e' || c[i] == 'i' || c[i] == 'o' || c[i] == 'u')
            continue;
        count += 1;
    }
    printf("Process %d Count = %d\n", rank, count);
    fflush(stdout);
    MPI_Gather(&count, 1, MPI_INT, b, 1, MPI_INT, 0, MPI_COMM_WORLD);
    if (rank == 0)
    {
        int tcount = 0;
        for (i = 0; i < n; i++)
            tcount += b[i];
        printf("Total non vowels = %d\n", tcount);
        fflush(stdout);
    }
    MPI_Finalize();
}