// sum of 0 to N (no use of reduction)

#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

#define N 10000000

int main (int argc, char *argv[]) {
	const int tnum = omp_get_max_threads();
	long long sum = 0, *localsum = NULL;

	localsum = calloc(tnum, sizeof(long long));

	// pass the initial value of localsum (zero) to each thread
	// and make every instance private to the corresponding thread
	#pragma omp parallel firstprivate(localsum)
	{
		int start = omp_get_thread_num();
		// divide it
		for (int i = start; i < N; i += tnum)
			localsum[start] += i;
	}

	// conquer it
	for (int i = 0; i < tnum; ++i)
		sum += localsum[i];

	printf("Sum = %lld\n", sum);
	free(localsum);
	return 0;
}