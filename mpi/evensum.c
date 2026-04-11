#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv) {
    int rank, size, n = 1000;
    int *data = NULL, local_sum = 0, total_sum = 0;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int local_n = n / size;
    int *local_data = malloc(local_n * sizeof(int));

    if (rank == 0) {
        data = malloc(n * sizeof(int));
        srand(time(NULL));
        for (int i = 0; i < n; i++) data[i] = rand() % 100;
    }

    // Distribute data to all processes
    MPI_Scatter(data, local_n, MPI_INT, local_data, local_n, MPI_INT, 0, MPI_COMM_WORLD);

    // Calculate local sum of evens
    for (int i = 0; i < local_n; i++) {
        if (local_data[i] % 2 == 0) local_sum += local_data[i];
    }

    // Combine all local sums into the total_sum at rank 0
    MPI_Reduce(&local_sum, &total_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Total sum of even numbers: %d\n", total_sum);
        free(data);
    }

    free(local_data);
    MPI_Finalize();
    return 0;
}