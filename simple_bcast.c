#include <mpi.h>
#include <stdio.h>
int main(int argc, char** argv){
	MPI_Init(NULL, NULL);
	int trial_runs = 10;
	int data = 100;
	int i;
	double total_bcast_time = 0.0;
	for(i= 0; i< trial_runs; i++){
		//Before calling bcast , you will call MPI_Barrier
		MPI_Barrier(MPI_COMM_WORLD);
		total_bcast_time -=MPI_Wtime();
		MPI_Bcast(&data, 1, MPI_INT, 0, MPI_COMM_WORLD);
		//After calling bcast, you will call MPI_Barrier
		MPI_Barrier(MPI_COMM_WORLD);
		total_bcast_time +=MPI_Wtime();

	}
	printf("Avg Time:%lf\n", total_bcast_time/trial_runs);

	MPI_Finalize();

}
