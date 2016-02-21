#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv){
	MPI_Init(NULL, NULL);
	
	int ping_pong_limit = 10;
	int ping_pong_count = 0;
	
	int world_size;
	int world_rank;
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);


	int partner_rank = (world_rank + 1)%2;
	while(ping_pong_count < ping_pong_limit){
		if(world_rank == ping_pong_count % 2){
			ping_pong_count = ping_pong_count + 1;
			MPI_Send(&ping_pong_count,1, MPI_INT, partner_rank, 0, MPI_COMM_WORLD );
			printf("Sent from: %d, Ping Pong Count:%d\n", world_rank, ping_pong_count);

		}else{
			MPI_Recv(&ping_pong_count, 1, MPI_INT, partner_rank, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			printf("Received from: %d, Ping Pong Count:%d\n", partner_rank, ping_pong_count );
		}



	}


	MPI_Finalize();
}
