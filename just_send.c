#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv ){
	MPI_Init(NULL, NULL);
	
	int world_size;
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);

	int world_rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

	int number;
	if(world_rank == 0){
		number = 200;
		MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
		printf("Sent %d\n", number);
	}else if(world_rank == 1){

		MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		printf("Received %d\n", number);
	}



	MPI_Finalize();

}
