#include <iostream>
#include <array>
#include <stack>
#include <sys/time.h>
#include <cstdio>

using namespace std;

double gettimeofday_sec(void)
{
	struct timeval t;
	gettimeofday(&t, NULL);
	return (double)t.tv_sec + (double)t.tv_usec * 1e-6;
}

int main(void)
{
	int a_size = 1;
	int j = 0;
	while(a_size < 10000000) {
		stack<int> p;
		j++;
		cout << j << " ";
		double tstart, tend;
		tstart = gettimeofday_sec();
		for (int i = 0; i < a_size; i++) {
			p.push(1);
		}

		int sum = 0;
		for (int i = 0; i < a_size; i++) {
			sum += p.top();
			p.pop();
		}

		tend = gettimeofday_sec();
		cout << (tend - tstart) << endl;

		a_size *= 2;
	}
	return 0;
}


