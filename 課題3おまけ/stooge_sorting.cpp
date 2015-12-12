#include <iostream>
#include <random>
#include <sys/time.h>

using namespace std;

int a[1000000];
int size;

double gettimeofday_sec(void)
{
	struct timeval t;
	gettimeofday(&t, NULL);
	return (double)t.tv_sec + (double)t.tv_usec * 1e-6;
}

void sort(int i, int j)
{
	if (a[i] > a[j]) {
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	if (j - i + 1 >= 3) {
		int t = (j - i + 1) / 3;
		sort(i, j - t);
		sort(i + t, j);
		sort(i, j - t);
	}
}

int main(void)
{
	size = 1;
	random_device rd;
	for (int t = 0; t < 12; t++) {
		size *= 2;
		for (int i = 0; i < size; i++) {
			a[i] = rd() % 1000;
		}
		double tstart, tend;
		tstart = gettimeofday_sec();
		sort(0, size - 1);
		tend = gettimeofday_sec();
		cout << tend - tstart << endl;
	}
	return 0;
}

