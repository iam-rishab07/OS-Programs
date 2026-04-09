/*
Q.2 Write an MPI program to find the max number from randomly generated 1000

numbers (stored in array) on a cluster (Hint: Use MPI_Reduce)
*/

//#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define N 1000

int main(int argc, char *argv[]) {
    int rank, size, i, max_l, max_g;
    int nums[N], l_nums[N];

    MPI_Init(&argc, &argv);
  //  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
   // MPI_Comm_size(MPI_COMM_WORLD, &size);

    int chunk = N / size;

    if (rank == 0) 
        for (i = 0; i < N; i++) nums[i] = rand() % 1000;

    // Distribute data to all processes
   // MPI_Scatter(nums, chunk, MPI_INT, l_nums, chunk, MPI_INT, 0, MPI_COMM_WORLD);

    // Find local max
    max_l = l_nums[0];
    for (i = 1; i < chunk; i++) 
        if (l_nums[i] > max_l) max_l = l_nums[i];

    // Reduce all local maximums to one global maximum at root
   // MPI_Reduce(&max_l, &max_g, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);

    if (rank == 0) printf("Global Maximum: %d\n", max_g);

    MPI_Finalize();
    return 0;
}