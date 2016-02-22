#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv){
	MPI_Init(NULL, NULL);
	int world_size;
	int world_rank;
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
	int no_of_runs = 10;
	int num_of_elements = 100;
	double mpi_bcast_time = 0.0;
	int i= 0;
	int *data = (int*)malloc(sizeof(int) * num_of_elements);
	for(i=0;i<no_of_runs;i++){
		MPI_Barrier(MPI_COMM_WORLD);
		mpi_bcast_time -=MPI_Wtime();
		MPI_Bcast(data, num_of_elements, MPI_INT, 0, MPI_COMM_WORLD);
		MPI_Barrier(MPI_COMM_WORLD);
		mpi_bcast_time += MPI_Wtime();
	}
	if(world_rank==0){
		printf("Avg time = %lf \n", mpi_bcast_time/ no_of_runs);
	}


	MPI_Finalize();
}
