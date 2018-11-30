// sum of 0 to N (using reduction - a better way)

#include <stdio.h>
#include <omp.h>

#define N 10000000

int main (int argc, char *argv[]) {
	const int tnum = omp_get_max_threads();
	long long sum = 0;

	// each thread sums a portion of the sequence, and they sync
	// after the loop reducing the results to a single sum
	#pragma omp parallel reduction(+:sum)
	{
		for (int i = omp_get_thread_num(); i < N; i += tnum)
			sum += i;
	}

	printf("Sum = %lld\n", sum);
	return 0;
}