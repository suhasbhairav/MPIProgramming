#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv){
	MPI_Init(NULL, NULL);
	
	//Get the number of processes
	int world_size;
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);
	
	//Get the rank of the process 
	int world_rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

	//Get the name of the processor
//	char processor_name[MPI_PROCESSOR_NAME];
//	int name_len;
//	MPI_Get_processor_name(MPI_PROCESSOR_NAME, &name_len);

	//Print a message
	printf("Hello world from rank %d out of %d processors\n",
		 world_rank, world_size);
	
	//Finalize the environment
	MPI_Finalize();


}
