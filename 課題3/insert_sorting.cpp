#include <iostream>
#include <random>
#include <sys/time.h>
#include <ostream>
#include <fstream>

using namespace std;

int a[1000000];

namespace {
	ofstream take_log("data_insert_cpp.log");
}

double gettimeofday_sec(void)
{
	struct timeval t;
	gettimeofday(&t, NULL);
	return (double)t.tv_sec + (double)t.tv_usec * 1e-6;
}

void insert(int size)
{
	for (int j = size; j >= 1; j--) {
		if (a[j] < a[j - 1]) {
			int temp = a[j];
			a[j] = a[j - 1];
			a[j - 1] = temp;
		} else {
			break;
		}
	}
}

int main(void)
{
	random_device rd;
	int a_size = 1;
	for (int i = 0; i < 18; i++) {
		a_size *= 2;
		for (int x = 0; x < a_size; x++) {
			a[x] = rd() % 1000;
		}
		double start, end;
		start = gettimeofday_sec();
		for (int p = 2; p <= a_size; p++) {
			insert(p);
		}
		end = gettimeofday_sec();

		cout << end - start << endl;
		take_log << end - start << endl;

	}

	return 0;
}
