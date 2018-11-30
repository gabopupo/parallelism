// Estimates the value of Pi using Riemann sum.

#include <stdio.h>
#include <omp.h>

#define N 1000000000
int main(int argc, char *argv[]) {
	long double x, dx = 1/(N * 1.0), pi = 0.0;

	// parallelize Pi computation loop for each N divisions
	// and reduce all parallel sums to one variable in the end 
	#pragma omp parallel for schedule(guided) reduction(+:pi) private(x)
	for (int i = 0; i < N; i++) {
		x = (i+0.5)*dx;
		pi += 4/(1+x*x);
	}

	pi *= dx;
	printf("Pi = %0.7Lf\n", pi);
	return 0;
}