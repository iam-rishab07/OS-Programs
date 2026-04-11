/*
Q2.) Write an MPI program to calculate sum and average of randomly generated 1000
numbers (stored in array) on a cluster
*/

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
        for (int i = 0; i < n; i++) data[i] = rand() % 100; // Random 0-99
    }

    // Distribute data
    MPI_Scatter(data, local_n, MPI_INT, local_data, local_n, MPI_INT, 0, MPI_COMM_WORLD);

    // Calculate local sum of all numbers in chunk
    for (int i = 0; i < local_n; i++) {
        local_sum += local_data[i];
    }

    // Collect and sum all local results at Rank 0
    MPI_Reduce(&local_sum, &total_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        float avg = total_sum / (float)n;
        printf("Total Sum: %d\n", total_sum);
        printf("Average: %.2f\n", avg);
        free(data);
    }

    free(local_data);
    MPI_Finalize();
    return 0;
}