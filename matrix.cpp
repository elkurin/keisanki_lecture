#include <iostream>
#include <sys/time.h>
#include <stdio.h>
#include <math.h>

using namespace std;

const int INF = 1000;

long long int x[INF][INF], y[INF][INF], ans[INF][INF];
//x[tate][yoko]

int t_max = 10;
/*
int x_yoko_size, x_tate_size;
int y_yoko_size;
int& y_tate_size = x_yoko_size;
*/
int size;

double gettimeofday_sec(void)
{
	struct timeval t;
	gettimeofday(&t, NULL);
	return (double)t.tv_sec + (double)t.tv_usec * 1e-6;
}

void init_matrix(void)
{
//	x_yoko_size = size;
//	y_tate_size = size;
//	x_yoko_size = size;
	for (int p = 0; p < size; p++) {
		for (int q = 0; q < size; q++) {
			x[p][q] = 1;
			y[p][q] = 1;
		}
	}
}


long long int matrix(int tate, int yoko)
{
	long long int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += x[tate][i] * y[i][yoko];
	}
	return sum;
}
/*
void show_matrix(void)
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%d ", ans[i][j]);
		}
		cout << endl;
	}
}
*/

int main(void)
{
	double tstart, tend;
	size = 1;
	for (int t = 0; t < t_max; t++) {
		init_matrix();
		tstart = gettimeofday_sec();

		for (int a = 0; a < size; a++) {
			for (int b = 0; b < size; b++) {
				ans[a][b] = matrix(a, b);
			}
		}
//		show_matrix();
		tend = gettimeofday_sec();
		cout << (double)((tend - tstart)) << endl;
		size *= 2;
	}

	return 0;
}

