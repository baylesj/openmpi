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

	printf("Running single threaded...\n");
	
	gettimeofday(&tv1, NULL);
	for (i = 0; i < max_value; ++i) {
		is_happy(i);
	}
	gettimeofday(&tv2, NULL);
	
	printf("values (%d,%d), time %f \n",
	        0, max_value,
	        (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec)
	        );

	return 0;
}
