#include <stdio.h>
#include <random>
#include <array>
#include <iostream>
#include <sys/time.h>

using namespace std;
int size;

double gettime(void)
{
	struct timeval t;
	gettimeofday(&t, NULL);
	return (double)t.tv_sec + (double)t.tv_usec * 1e-6;
}

void show(int x[], int n)
{
	int i;
	for (i = 0; i < n; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}
void sort(int x[], int start, int end)
{
	int fore = start;
	int back = end;
	int pivot = x[(start + end) / 2];

	while(1) {
		while(x[fore] < pivot) fore++;
		while(pivot < x[back]) back--;
		if (fore >= back) break;

		int temp = x[fore];
		x[fore] = x[back];
		x[back] = temp;

		fore++;
		back--;
	}
//	show(x, size);

	if (start < fore - 1) sort(x, start, fore - 1);
	if (back + 1 < end) sort(x, back + 1, end);
}

int main(void)
{
	random_device rd;
	int x[1000000];
	int i;
	int size = 1;
	for (int j = 0; j < 18; j++) {
		size *= 2;
		for (i = 0; i < size; i++) {
			x[i] = rd() % 100;
		}
		double tstart = gettime();
//		show(x, size);
		sort(x, 0, size - 1);
//		show(x, size);
		double tend = gettime();
		cout << tend - tstart << endl;
	}
	return 0;
}
