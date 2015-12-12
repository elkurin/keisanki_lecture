#include <iostream>
#include <map>
#include <vector>
#include <sys/time.h>
#include <random>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++) 
#define vec vector
#define pb push_back

double gettimeofday_sec(void)
{
	struct timeval t;
	gettimeofday(&t, NULL);
	return (double)t.tv_sec + (double)t.tv_usec * 1e-6;
}

int main(void)
{
	random_device rd;
	
	int size = 1;
	int max_b = 1000;

	rep(t, 18) {
		size *= 2;
		vec<int> a;
		vec<int> b(max_b, 0);
		rep(i, size) {
			a.pb(rd() % max_b);
		}
		double tstart, tend;
		tstart = gettimeofday_sec();
		int k = 0;
		rep(i, max_b) {
			if (a[k] == i) {
				b[i]++;
				a.erase(a.begin() + k);
			} else {
				k++;
			}
			if (k == (int)a.size()) break;
		}
		tend = gettimeofday_sec();
		cout << tend - tstart << endl;
	}
	return 0;
}
