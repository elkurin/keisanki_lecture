import java.util.Random;

class bucket_sorting
{
	public static void main(String args[])
	{
		int max_b = 1000;
		int size = 1;
		int a[], b[];
		a = new int [1000000];
		b = new int [1000];
		Random rnd = new Random();
		for (int t = 0; t < 18; t++) {
			size *= 2;
			for (int i = 0; i < size; i++) {
				a[i] = rnd.nextInt(1000);
			}
			long tstart, tend;
			tstart = System.nanoTime();
			for (int i = 0; i < max_b; i++) {
				for (int j = 0; j < size; j++) {
					if (a[j] == i) {
						b[i]++;
					}
				}
			}
			int k = 0;
			for (int i = 0; i < max_b; i++) {
				for (int j = 0; j < b[i]; j++) {
					a[k] = i;
					k++;
				}
			}
			tend = System.nanoTime();
			System.out.println((tend - tstart) / 1000000000f);
		}
	}
}
