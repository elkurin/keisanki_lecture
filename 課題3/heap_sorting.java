import java.util.Random;

class heap_sorting
{
	static void change(int i, int r, int a[])
	{
		int j;
		int keep = a[i];

		while(true) {
			j = 2 * i + 1;
			if (j > r) break;
			if (j < r) {
				if (a[j + 1] > a[j]) {
					int temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
				}
			}
			if (keep >= a[j]) break;
			a[i] = a[j];
			i = j;
		}
		a[i] = keep;
	}

	static void heap_sort(int a[], int size)
	{
		for (int i = size / 2 - 1; i >= 0; i--) {
			change(i, size - 1, a);
		}
		for (int i = size - 1; i > 0; i--) {
			int temp = a[0];
			a[0] = a[i];
			a[i] = temp;
			change(0, i - 1, a);
		}
	}

	public static void main(String args[])
	{
		int a[];
		a = new int [1000000];
		Random rnd = new Random();
		int size = 1;
		for (int t = 0; t < 18; t++) {
			size *= 2;
			for (int i = 0; i < size; i++) {
				a[i] = rnd.nextInt(1000);
			}
			long tstart = System.nanoTime();
			heap_sort(a, size);
			long tend = System.nanoTime();

			System.out.println((tend - tstart) / 1000000000f);
		}
	}
}
