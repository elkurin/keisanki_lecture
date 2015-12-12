#include <iostream>
#include <array>
#include <sys/time.h>
#include <random>

using namespace std;

double gettime(void)
{
	struct timeval t;
	gettimeofday(&t, NULL);
	return (double)t.tv_sec + (double)t.tv_usec * 1e-6;
}

int main(void)
{
	array<int, 1000000> a;
	random_device rd;
	for (int p_size = 1; p_size <= 18; p_size++) {
		int size = (int)pow(2, p_size);
		for (int i = 0; i < size; i++) {
			a.at(i) = rd();
		}
		
		double start = gettime();
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (a.at(j) > a.at(j + 1)) {
					int temp = a.at(j);
					a.at(j) = a.at(j + 1);
					a.at(j + 1) = temp;
				}
			}
		}
		double end = gettime();

		cout << end - start << endl;
	}

	return 0;
}


