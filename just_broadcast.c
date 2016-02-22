#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>

int main(int argc, char **argv){
	MPI_Init(NULL, NULL);
	int world_size;
	int world_rank;

	MPI_Comm_size(MPI_COMM_WORLD, &world_size);
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
	double mpi_time=0.0;
	int number = 10000;
	int runs = 20;
	int *data = (int *)malloc(sizeof(int) * number);
	int i;
	for(i=0;i<runs;i++){
		MPI_Barrier(MPI_COMM_WORLD);
		mpi_time -= MPI_Wtime();
		MPI_Bcast(data, number, MPI_INT, 0, MPI_COMM_WORLD);
		MPI_Barrier(MPI_COMM_WORLD);
		mpi_time += MPI_Wtime();
	}
	if(world_rank == 0){
		printf("Avg time = %lf \n", mpi_time / runs);
	}
	
	MPI_Finalize();

}
