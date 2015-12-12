#include <iostream>
#include <array>
#include <sys/time.h>
#include <random>
#include <string>

using namespace std;

double gettimeofday_sec(void)
{
	struct timeval t;
	gettimeofday(&t, NULL);
	return (double)t.tv_sec + (double)t.tv_usec * 1e-6;
}

random_device rd;

int a[1000000];

typedef struct
{
	int one;
	int ten;
	int hund;
} dev;

dev b[1000000];

int size;

void put_in(void)
{
	for (int i = 0; i < size; i++) {
		b[i].one = a[i] % 10;
		b[i].ten = a[i] % 100 / 10;
		b[i].hund = a[i] / 100;
	}
}

void radix(void)
{
	int k = 0;
	int c[1000000];
	
	put_in();	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < size; j++) {
			if (b[j].one == i) {
				c[k] = a[j];
				k++;
			}
		}
	}
	for (int i = 0; i < size; i++) {
		a[i] = c[i];
	}
	k = 0;
	put_in();
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < size; j++) {
			if (b[j].ten == i) {
				c[k] = a[j];
				k++;
			}
		}
	}
	for (int i = 0; i < size; i++) {
		a[i] = c[i];
	}
	k = 0;
	put_in();
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < size; j++) {
			if (b[j].hund == i) {
				c[k] = a[j];
				k++;
			}
		}
	}
	for (int i = 0; i < size; i++) {
		a[i] = c[i];
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
		radix();
		tend = gettimeofday_sec();

		cout << tend - tstart << endl;
	}
	return 0;
}



