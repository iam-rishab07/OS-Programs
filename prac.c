#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<mpi.h>

int main(int argc, char** argv)
{
    int rank, size, total_sum=0, local_sum=0, n=1000;
    int *data = NULL;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);

    int local_n = n/size;
    int *local_data = malloc(local_n*sizeof(int));

    if(rank==0)
    {
        data = malloc(n*sizeof(int));
        srand(time(0));
        for(int i=0;i<n;i++) data[i]=rand()%100;
    }
}