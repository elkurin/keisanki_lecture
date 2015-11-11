#include <iostream>
#include <random>
#include <sys/time.h>
#include <ostream>
#include <fstream>

using namespace std;

namespace {
	ofstream take_log("data_bogo_cpp");
}

random_device rd;

int a[1000000];
int b[1000000];
int size = 1;

double gettimeofday_sec(void)
{
	struct timeval t;
	gettimeofday(&t, NULL);
	return (double)t.tv_sec + (double)t.tv_usec * 1e-6;
}

void shuffle(void)
{
	int k = 0;
	for (int i = size; i >= 2; i--) {
		int get = rd() % i;
		b[k] = a[get];
		k++;
		a[get] = a[i - 1];
	}
	b[k] = a[0];
	for (int i = 0; i < size; i++) {
		a[i] = b[i];
	}
}

int main(void)
{
	for (int t = 0; t < 4; t++) {
		size *= 2;
		int count = 1;
		for (int i = 0; i < size; i++) {
			a[i] = rd() % 1000;
		}
		double tstart, tend;
		tstart = gettimeofday_sec();
		while(1) {
			int check = 1;
			for (int i = 0; i < size - 1; i++) {
				if (a[i] > a[i + 1]) {
					check = 0;
					break;
				}
			}
			if (check == 1) break;
			shuffle();
			count++;
		}
		tend = gettimeofday_sec();
		cout << tend - tstart << endl;
		take_log << tend - tstart << endl;
		for (int i = 0; i < size; i++) {
			cout << a[i] << endl;
		}
		cout << "time = " << count << endl;
	}
	return 0;
}
			
