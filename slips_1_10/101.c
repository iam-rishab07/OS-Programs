/*
Q.1 Write an MPI program to calculate sum and average of randomly generated 1000

numbers (stored in array) on a cluster
*/

//#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define N 1000

int main(int argc, char* argv[]) {
    int rank, size, i, l_sum = 0, g_sum = 0, nums[N];

    MPI_Init(&argc, &argv);
    //MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    //MPI_Comm_size(MPI_COMM_WORLD, &size);

    int chunk = N / size;
    int l_nums[chunk];

    if (rank == 0) 
        for (i = 0; i < N; i++) nums[i] = rand() % 100;

    // Split array and send to all processes
    //MPI_Scatter(nums, chunk, MPI_INT, l_nums, chunk, MPI_INT, 0, MPI_COMM_WORLD);

    for (i = 0; i < chunk; i++) l_sum += l_nums[i];

    // Collect all local sums and add them at rank 0
    //MPI_Reduce(&l_sum, &g_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0)
        printf("Sum: %d\nAvg: %.2f\n", g_sum, (double)g_sum / N);

    MPI_Finalize();
    return 0;
}