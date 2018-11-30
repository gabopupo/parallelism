// Every thread prints Hello World.

#include <stdio.h>
#include <omp.h>

int main (int argc, char *argv[]) {
	// everything inside the block below will be parallelized
	#pragma omp parallel
	{
		int id = omp_get_thread_num(); // get thread number (local scope)
		printf("Thread %d says \"Hello world!\"\n", id);
	}
	// the threads will sync after it
	return 0;
}