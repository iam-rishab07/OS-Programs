#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv) {
    int rank, size, n = 1000, local_sum = 0, total_sum = 0;
    int *data = NULL;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int local_n = n / size;
    int *local_data = malloc(local_n * sizeof(int));

    if (rank == 0) {
        data = malloc(n * sizeof(int));
        srand(time(0));
        for (int i = 0; i < n; i++) data[i] = rand() % 100;
    }

    // Send chunks of data to all processes
    MPI_Scatter(data, local_n, MPI_INT, local_data, local_n, MPI_INT, 0, MPI_COMM_WORLD);

    // Each process calculates sum of odds in its chunk
    for (int i = 0; i < local_n; i++) {
        if (local_data[i] % 2 != 0) local_sum += local_data[i];
    }

    // Collect all local sums and add them at Rank 0
    MPI_Reduce(&local_sum, &total_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Final Sum of Odd Numbers: %d\n", total_sum);
        free(data);
    }

    free(local_data);
    MPI_Finalize();
    return 0;
}