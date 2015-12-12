#include <iostream>
#include <random>
#include <math.h>
#include <sys/time.h>

using namespace std;

int size;
int a[1000000];

random_device rd;

double gettimeofday_sec(void)
{
	struct timeval t;
	gettimeofday(&t, NULL);
	return (double)t.tv_sec + (double)t.tv_usec * 1e-6;
}

void change(int i, int r)
{
	int j;
	int keep = a[i];

	while(1) {
		j = 2 * i + 1;
		if (j > r) break;
		if (j < r) {
			if (a[j + 1] > a[j]) {
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
		if (keep >= a[j]) break;
		a[i] = a[j];
		i = j;
	}
	a[i] = keep;
}

void heap_sort(void)
{
	for (int i = size / 2 - 1; i >= 0; i--) {
		change(i, size - 1);
	}
	for (int i = size - 1; i > 0; i--) {
		int temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		change(0, i - 1);
	}
}

int main(void)
{
	size = 1;
	for (int t = 0; t < 18; t++) {
		size *= 2;
		for (int i = 0; i < size; i++) {
			a[i] = rd() % 1000;
		}
		double tstart, tend;
		tstart = gettimeofday_sec();
		heap_sort();
		tend = gettimeofday_sec();
		cout << tend - tstart << endl;
	}
	return 0;
}

