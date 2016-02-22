#include <mpi.h>
#include <stdio.h>


int main(int argc, char **argv){
	MPI_Init(NULL, NULL);
	
	int world_size;
	int world_rank;
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

	int color = world_rank / 4;
	int row_size;
	int row_rank;
	MPI_Comm row_comm;
	MPI_Comm_split(MPI_COMM_WORLD, color, world_rank, &row_comm);

	MPI_Comm_size(row_comm, &row_size);
	MPI_Comm_rank(row_comm, &row_rank);

	printf("World Rank:%d \t World Size:%d \t Row Rank: %d\t Row Size: %d\n", world_rank, world_size, row_rank, row_size);


	MPI_Finalize();


}
