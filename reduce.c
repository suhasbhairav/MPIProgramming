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
	
	srand(time(NULL));
	int num_elements_per_proc = 100;
	float *rand_nums = (float *)malloc(sizeof(float) * num_elements_per_proc);
	int i;
	for(i=0; i<num_elements_per_proc; i++){
		rand_nums[i] = (rand() / (float)RAND_MAX);
	}
	int local_sum;
	
	for(i=0; i<num_elements_per_proc; i++){

		local_sum +=rand_nums[i];

	}

	printf("Avg for process %d is %f, Local sum is %f\n", world_rank,(float) (local_sum/num_elements_per_proc), local_sum);
	float global_sum;
	MPI_Reduce(rand_nums, &global_sum, 1, MPI_FLOAT, MPI_SUM, 0, MPI_COMM_WORLD);
	if(world_rank == 0){
		printf("Avg for process %d is %f, Global sum is %f\n", world_rank, global_sum/(world_size * num_elements_per_proc), global_sum);


	}



	MPI_Finalize();


}
