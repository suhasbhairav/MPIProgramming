#include <stdio.h>
#include <mpi.h>

//A function simulating bcast
void bcast_wrapper(void* data, int count, MPI_Datatype datatype, int root,
			MPI_Comm communicator){

	int world_size;
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);

	int world_rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

	
	if(world_rank == root){
		int i;
		for(i=0; i< world_size; i++){
			if(i!=world_rank){
				MPI_Send(data, count, datatype, i, 0,communicator);
				printf(" i:%d", i);
			}
		}
	}else{

		MPI_Recv(data, count, datatype, root, 0, communicator, MPI_STATUS_IGNORE);
		printf(" root: %d", root);

	}




}
int main(int argc, char** argv){
	MPI_Init(NULL, NULL);
	int data = 100;
	bcast_wrapper(&data, 1, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Finalize();


}
