#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv){
	//Initialize
	MPI_Init(NULL, NULL);
	
	//Number of processes
	int world_size;
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);

	//Rank of the process
	int world_rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

	printf("I'm printing...Rank %d  :: Processor %d\n", world_rank, world_size);
	//Cleanup
	MPI_Finalize();








}
