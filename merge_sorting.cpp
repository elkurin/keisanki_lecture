#include <iostream>
#include <stdio.h>
#include <sys/time.h>
#include <ostream>
#include <fstream>

using namespace std;

namespace {
	ofstream take_log("data_merge_cpp.log");
}

int a[1000000];
int b[1000000];

double gettimeofday_sec(void)
{
	struct timeval t;
	gettimeofday(&t, NULL);
	return (double)t.tv_sec + (double)t.tv_usec * 1e-6;
}

void merge(int start, int end)
{
	int size = end - start + 1;
	int temp;
	int mid = (start + end) / 2;
	if (size > 2) {
		merge(start, mid);
		merge(mid + 1, end);
	}
	int one, two, top;
	one = start;
	two = mid + 1;
	top = start;

	while(1) {
		if (a[one] < a[two]) {
			b[top] = a[one];
			top++;
			one++;
			if (one > mid) {
				for (int i = two; i <= end; i++) {
					b[top] = a[i];
					top++;
				}
			}
		} else {
			b[top] = a[two];
			top++;
			two++;
			if (two > end) {
				for (int i = one; i <= mid; i++) {
					b[top] = a[i];
					top++;
				}
			}
		}
		if (top > end) break;
	}
	for (int i = start; i <= end; i++) {
		a[i] = b[i];
	}
}

int main(void)
{
	int size = 1;
	for (int t = 0; t < 18; t++) {
		size *= 2;
		for (int j = 0; j < size; j++) {
			a[j] = rand() % 1000;
		}

		double tstart, tend;
		tstart = gettimeofday_sec();
		merge(0, size - 1);
		tend = gettimeofday_sec();

		cout << tend - tstart << endl;
		take_log << tend - tstart << endl;
	}
	return 0;
}
