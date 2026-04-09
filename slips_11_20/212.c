//Q.2 Write an MPI program to calculate sum of all even randomly generated 1000
//numbers (stored in array) on a cluster

//#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define N 1000

int main(int argc, char* argv[]) {
    int rank, size, i, l_sum = 0, g_sum = 0, nums[N];

    MPI_Init(&argc, &argv);
   // MPI_Comm_rank(MPI_COMM_WORLD, &rank);
   // MPI_Comm_size(MPI_COMM_WORLD, &size);

    int chunk = N / size;
    int l_nums[chunk];

    if (rank == 0) 
        for (i = 0; i < N; i++) nums[i] = rand() % 100;

    // Distribute data to all processes
    //MPI_Scatter(nums, chunk, MPI_INT, l_nums, chunk, MPI_INT, 0, MPI_COMM_WORLD);

    // Calculate local sum of EVEN numbers only
    for (i = 0; i < chunk; i++) {
        if (l_nums[i] % 2 == 0) 
            l_sum += l_nums[i];
    }

    // Collect and sum all local even-sums at rank 0
    //MPI_Reduce(&l_sum, &g_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) printf("Sum of even numbers: %d\n", g_sum);

    MPI_Finalize();
    return 0;
}