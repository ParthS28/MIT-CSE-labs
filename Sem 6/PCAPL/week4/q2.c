#include <mpi.h>
#include <stdio.h>
#include <string.h>
void Error_Handler(int error_code)
{
    if (error_code != MPI_SUCCESS)
    {
        // printf("hello");
        char error_string[1024];
        int length_of_error_string, error_class;
        MPI_Error_class(error_code, &error_class);
        MPI_Error_string(error_code, error_string, &length_of_error_string);
        printf("%d %s\n", error_class, error_string);
    }
}

int main(int argc, char *argv[])
{
    int rank, size;
    int i = 0, j; int error_code;
    int k = 0, fac = 1, ans[1000], sum = 0;
    int n, a[100][100], b[100];
    float x, y, area, pi1;
    MPI_Init(&argc, &argv);
    
    // Set the error handler to MPI_ERRORS_RETURN
    MPI_Errhandler_set(MPI_COMM_WORLD, MPI_ERRORS_RETURN);
    error_code = MPI_Comm_size(MPI_COMM_WORLD, &size);
    Error_Handler(error_code);
    error_code = MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    Error_Handler(error_code);
    int error = MPI_Bcast(&size, 1, MPI_INT, 0, MPI_COMM_WORLD);
    Error_Handler(error_code);
    x = (float)(rank + 1) / size;
    y = 4.f / (1 + (x * x));
    area = (1 / (float)size) * y;
    MPI_Reduce(&area, &pi1, 1, MPI_FLOAT, MPI_SUM, 0, MPI_COMM_WORLD);
    if (rank == 0)
    {
        fprintf(stdout, "%f\n", pi1);
        fflush(stdout);
    }
    MPI_Finalize();
    return 0;
}  