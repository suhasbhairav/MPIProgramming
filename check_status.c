#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv){
	MPI_Init(NULL, NULL);
	
	int world_size;
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);

	int world_rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

	if(world_size !=2){
		fprintf(stderr, "Must use two processes\n");
		MPI_Abort(MPI_COMM_WORLD, 1);
	}
	const int MAX_NUMBERS = 100;
	int numbers[MAX_NUMBERS];
	int number_amount;
	if(world_rank == 0){
		srand(time(NULL));
		number_amount = (rand() / (float)RAND_MAX) * MAX_NUMBERS;
		MPI_Send(numbers, number_amount, MPI_INT, 1, 0, MPI_COMM_WORLD);
		printf("Sender is 0. Numbers sent is %d. Received process is 1.\n",number_amount);
	}else if(world_rank == 1){
		MPI_Status status;
		MPI_Recv(numbers, MAX_NUMBERS, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
		MPI_Get_count(&status, MPI_INT, &number_amount);
		printf("Numbers received is %d. Source is %d. Tag is %d\n", number_amount, status.MPI_SOURCE, status.MPI_TAG);


	}
	MPI_Barrier(MPI_COMM_WORLD);
	MPI_Finalize();

}
