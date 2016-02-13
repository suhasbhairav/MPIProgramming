#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv){
	//Initialize
	MPI_Init(NULL, NULL);
	int world_size;
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);

	int world_rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

	printf("\nRank:%d -- Processors:%d", world_rank, world_size);


	//Cleanup
	MPI_Finalize();



}
