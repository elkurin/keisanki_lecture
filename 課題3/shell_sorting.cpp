#include <iostream>
#include <random>
#include <sys/time.h>

using namespace std;

int a[1000000];
int size;

random_device rd;

double gettimeofday_sec(void)
{
	struct timeval t;
	gettimeofday(&t, NULL);
	return (double)t.tv_sec + (double)t.tv_usec * 1e-6;
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

		int j = 3 * (size / 3) + 1;
		while(1) {
			while(1) {
				int check = 0;
				for (int i = 0; i < size - j; i++) {
					if (a[i] > a[i + j]) {
						int temp = a[i];
						a[i] = a[i + j];
						a[i + j] = temp;
						check = 1;
					}
				}
				if (check == 0) break;
			}
			if (j == 1) break;
			j -= 3;
		}

		tend = gettimeofday_sec();

		cout << tend - tstart << endl;
	}
	return 0;
}


