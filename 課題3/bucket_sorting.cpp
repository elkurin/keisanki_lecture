#include <iostream>
#include <random>
#include <sys/time.h>

using namespace std;

const int max_b = 1000;

int size = 1;
int a[1000000];
int b[max_b];

double gettimeofday_sec(void)
{
	struct timeval t;
	gettimeofday(&t, NULL);
	return (double)t.tv_sec + (double)t.tv_usec * 1e-6;
}

int main(void)
{
	random_device rd;

	for (int t = 0; t < 18; t++) {
		size *= 2;
		for (int i = 0; i < size; i++) {
			a[i] = rd() % max_b;
		}
		double tstart, tend;
		tstart = gettimeofday_sec();
		for (int i = 0; i < max_b; i++) {
			for (int j = 0; j < size; j++) {
				if (a[j] == i) {
					b[i]++;
				}
			}
		}
		int k = 0;
		for (int i = 0; i < max_b; i++) {
			for (int j = 0; j < b[i]; j++) {
				a[k] = i;
				k++;
			}
		}
		tend = gettimeofday_sec();
		cout << tend - tstart << endl;
	}
	return 0;
}


