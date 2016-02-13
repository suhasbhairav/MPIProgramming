#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv){
	MPI_Init(NULL, NULL);
	
	int world_size;
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);
	
	int world_rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

	int token;
	//Care must be taken to prevent deadlock. But I've not understood this logic
	if(world_rank!=0){
		MPI_Recv(&token, 1, MPI_INT, (world_rank -1), 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		printf("Sender is %d. Receiver is %d. Token is %d\n", world_rank-1, world_rank, token);
	}
	
	//For eg: If 0 is sending to 1, then destination is obtained by (0 +1) % world_size
	MPI_Send(&token, 1, MPI_INT, (world_rank+1)%world_size, 0, MPI_COMM_WORLD);
	
	if(world_rank == 0){
		//Master receives the token from the last process. So source is world_size - 1.
		MPI_Recv(&token, 1, MPI_INT, world_size-1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		printf("Sender is %d. Receiver is %d. Token is %d\n", world_size-1, world_rank, token);
	}

	MPI_Finalize();


}

