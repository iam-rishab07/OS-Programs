/*
Q.2 Write an MPI program to find the min number from randomly generated 1000

numbers (stored in array) on a cluster (Hint: Use MPI_Reduce)
*/

//#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define N 1000

int main(int argc, char* argv[]) {
    int rank, size, i, min_l, min_g, nums[N];

    MPI_Init(&argc, &argv);
    //MPI_Comm_rank(MPI_COMM_WORLD, &rank);
   // MPI_Comm_size(MPI_COMM_WORLD, &size);

    int chunk = N / size;
    int l_nums[chunk];

    if (rank == 0) 
        for (i = 0; i < N; i++) nums[i] = rand() % 1000;

    // Distribute chunks to all processes
    //MPI_Scatter(nums, chunk, MPI_INT, l_nums, chunk, MPI_INT, 0, MPI_COMM_WORLD);

    // Find local minimum
    min_l = l_nums[0];
    for (i = 1; i < chunk; i++) 
        if (l_nums[i] < min_l) min_l = l_nums[i];

    // Reduce all local minimums to one global minimum at rank 0
   // MPI_Reduce(&min_l, &min_g, 1, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);

    if (rank == 0) printf("Global Minimum: %d\n", min_g);

    MPI_Finalize();
    return 0;
}