#include <sys/time.h>
#include <stdio.h>

int a[100000000];
int a_size;

double gettimeofday_sec(void)
{
	struct timeval t;
	gettimeofday(&t, NULL);
	return (double)t.tv_sec + (double)t.tv_usec * 1e-6;
}

int main(void)
{
	a_size = 8;
	int j = 0;
	while(a_size < 10000000) {
	a_size *= 2;
	j++;
	printf("%d ", j);
	double tstart, tend;
	tstart = gettimeofday_sec();
	for (int i = 0; i < a_size; i++) {
		a[i] = 1;
	}

	int sum = 0;
	for (int i = a_size - 1; i >= 0; i--) {
		sum += a[i];
	}
	
	tend = gettimeofday_sec();
	printf("%f \n", (tend - tstart));
	}
	return 0;
}
