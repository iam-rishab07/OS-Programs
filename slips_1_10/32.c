/*
Q2.) Write an MPI program to calculate sum and average of randomly generated 1000
numbers (stored in array) on a cluster
*/

//#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define N 1000

int main(int argc, char* argv[]) {
    int rank, size, l_sum = 0, g_sum = 0, i;
    int root = 0, nums[N], l_nums[N];

    MPI_Init(&argc, &argv);
    //MPI_Comm_rank(MPI_COMM_WORLD, &rank);
   // MPI_Comm_size(MPI_COMM_WORLD, &size);

    int c_size = N / size; // Chunk size per process

    if (rank == root) 
        for (i = 0; i < N; i++) nums[i] = rand() % 100;

    // Distribute data
    //MPI_Scatter(nums, c_size, MPI_INT, l_nums, c_size, MPI_INT, root, MPI_COMM_WORLD);

    // Local calculation
    for (i = 0; i < c_size; i++) l_sum += l_nums[i];

    // Collect and sum results
    //MPI_Reduce(&l_sum, &g_sum, 1, MPI_INT, MPI_SUM, root, MPI_COMM_WORLD);

    if (rank == root)
        printf("Sum: %d\nAvg: %.2f\n", g_sum, (double)g_sum / N);

    MPI_Finalize();
    return 0;
}