/*
Q.2 Write an MPI program to find the min number from randomly generated 1000

numbers (stored in array) on a cluster (Hint: Use MPI_Reduce)
*/

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv) {
    int rank, size, n = 1000, local_min, total_min;
    int *data = NULL;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int local_n = n / size;
    int *local_data = malloc(local_n * sizeof(int));

    if (rank == 0) {
        data = malloc(n * sizeof(int));
        srand(time(0));
        for (int i = 0; i < n; i++) data[i] = rand() % 10000; // Random 0-9999
    }

    MPI_Scatter(data, local_n, MPI_INT, local_data, local_n, MPI_INT, 0, MPI_COMM_WORLD);

    // 1. Initialize local_min with the first element of the chunk
    local_min = local_data[0];
    for (int i = 1; i < local_n; i++) {
        if (local_data[i] < local_min) local_min = local_data[i];
    }

    // 2. Use MPI_MIN to find the smallest among all local_mins
    MPI_Reduce(&local_min, &total_min, 1, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("The minimum number is: %d\n", total_min);
        free(data);
    }

    free(local_data);
    MPI_Finalize();
    return 0;
}