// sum of 0 to N (using reduction - parallelizing a loop)
#include <stdio.h>
#include <omp.h>

#define N 10000000

int main (int argc, char *argv[]) {
	long long sum = 0;

	#pragma omp parallel for schedule(guided) reduction(+:sum)
	for (int i = 0; i < N; i++)
		sum += i;

	printf("Sum = %lld\n", sum);
	return 0;
}