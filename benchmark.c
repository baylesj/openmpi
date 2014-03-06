#include <mpi.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

#include "happy.h"

static const int max_value = 2500000;

int main(int argc, char **argv) {
	int i, me, nprocs, namelen;
	char processor_name[MPI_MAX_PROCESSOR_NAME];
	struct timeval tv1, tv2;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &me);
	MPI_Get_processor_name(processor_name, &namelen);

	// MULTITHREADED BENCHMARK
	int window = max_value / nprocs;
	int i_min = window * me;
	int i_max = window * (me + 1) - 1;

	gettimeofday(&tv1, NULL);
	for (i = i_min; i <= i_max; ++i) {
		is_happy(i);
	}
	gettimeofday(&tv2, NULL);
	
	printf("Process %d/%d on %s, values (%d,%d), time %f\n", me, nprocs, processor_name, i_min, i_max,
	        (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec));
	MPI_Finalize();
	

	return 0;
}
