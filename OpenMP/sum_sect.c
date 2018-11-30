// sum of 0 to N (demonstrates the use of sections and critical regions)

#include <stdio.h>
#include <omp.h>

#define N 10000000

int main (int argc, char *argv[]) {
	long long sum_e = 0, sum_o = 0, sum = 0;

	#pragma omp parallel sections
	{
		#pragma omp section
		{
			for (int i = 0; i < N; i += 2)
				sum_e += i;
			#pragma omp critical(even)
			sum += sum_e;
		}

		#pragma omp section
		{
			for (int i = 1; i < N; i += 2)
				sum_o += i;
			#pragma omp critical(odd)
			sum += sum_o;
		}		
	}
	printf("Sum = %lld\n", sum);
	return 0;
}