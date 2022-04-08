#include <mpi.h>
#include <stdio.h>
#include <string.h>
#define BUFSIZE 100
void Error_Handler(int error_code);
int main(int argc, char *argv[])
{
    int size, rank;
    int sum = 0;
    int fact = 1;
    MPI_Init(&argc, &argv);
    MPI_Errhandler_set(MPI_COMM_WORLD, MPI_ERRORS_RETURN);
    int error_code;
    error_code = MPI_Comm_size(MPI_COMM_WORLD, &size);
    error_code = MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    Error_Handler(error_code);
    int sendval = rank + 1;
    error_code = MPI_Scan(&sendval, &fact, 1, MPI_INT, MPI_PROD, MPI_COMM_WORLD);
    Error_Handler(error_code);
    fprintf(stdout, "process[%d]: fact is %d\n", rank, fact);
    fflush(stdout);
    MPI_Scan(&fact, &sum, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
    if (rank == size - 1)
        printf("Answer is: %d\n", sum);
    return 0;
}
void Error_Handler(int error_code)
{
    if (error_code != MPI_SUCCESS)
    {
        // printf("hello");
        char error_string[BUFSIZE];
        int length_of_error_string, error_class;
        MPI_Error_class(error_code, &error_class);
        MPI_Error_string(error_code, error_string, &length_of_error_string);
        printf("%d %s\n", error_class, error_string);
    }
}