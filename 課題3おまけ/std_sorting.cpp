#include <iostream>
#include <stdio.h>
#include <sys/time.h>
#include <random>
#include <algorithm>

using namespace std;

double gettimeofday_sec(void)
{
	struct timeval t;
	gettimeofday(&t, NULL);
	return (double)t.tv_sec + (double)t.tv_usec * 1e-6;
}

random_device rd;

const int n = 100000;

int main(void)
{
	double sum = 0;
	for (int t = 0; t < 100; t++) {
		int a[n];
		for (int i = 0; i < n; i++) {
			a[i] = rd() % 1000;
		}
		double tstart, tend;
		tstart = gettimeofday_sec();
		sort(a, a + n);
		tend = gettimeofday_sec();

		cout << tend - tstart << endl;
		sum += tend - tstart;
	}
	cout << endl << sum << endl;
	return 0;
}
	
	
