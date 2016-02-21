#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv){
	MPI_Init(NULL, NULL);

	//NO of processes
	int world_size;
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);

	int world_rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
	
	printf("Just saying hi from a basic program. No of processes : %d, Rank: %d\n", world_size, world_rank);


	MPI_Finalize();


}
