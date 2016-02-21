#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv){
	MPI_Init(NULL, NULL);
	
	int world_size;
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);

	int world_rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

	printf("No of processes: %d , Rank: %d\n", world_size, world_rank);

	MPI_Finalize();

}
