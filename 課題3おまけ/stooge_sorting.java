import java.util.Random;

class stooge_sorting
{
	static void sort(int a[], int i, int j)
	{
		if (a[i] > a[j]) {
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
		if (j - i + 1 >= 3) {
			int t = (j - i + 1) / 3;
			sort(a, i, j - t);
			sort(a, i + t, j);
			sort(a, i, j - t);
		}
	}

	public static void main(String args[])
	{
		int size = 1;
		int a[];
		a = new int [1000000];
		Random rnd = new Random();
		for (int t = 0; t < 12; t++) {
			size *= 2;
			for (int i = 0; i < size; i++) {
				a[i] = rnd.nextInt(1000);
			}
			long tstart = System.nanoTime();
			sort(a, 0, size - 1);
			long tend = System.nanoTime();
			System.out.println((tend - tstart) / 1000000000f);
		}
	}
}
