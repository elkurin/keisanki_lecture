import java.util.Random;

class radix_sorting
{
	public static void main(String args[])
	{
		int b[];
		b = new int [1000000];
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
			
			int k = 0;
			int c[];
			c = new int [1000000];
			for (int i = 0; i < size; i++) {
				b[i] = a[i] % 10;
			}
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < size; j++) {
					if (b[j] == i) {
						c[k] = a[j];
						k++;
					}
				}
			}
			for (int i = 0; i < size; i++) {
				a[i] = c[i];
			}
			k = 0;
			for (int i = 0; i < size; i++) {
				b[i] = a[i] % 100 / 10;
			}
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < size; j++) {
					if (b[j] == i) {
						c[k] = a[j];
						k++;
					}
				}
			}
			for (int i = 0; i < size; i++) {
				a[i] = c[i];
			}
			k = 0;
			for (int i = 0; i < size; i++) {
				b[i] = a[i] / 100;
			}
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < size; j++) {
					if (b[j] == i) {
						c[k] = a[j];
						k++;
					}
				}
			}
			for (int i = 0; i < size; i++) {
				a[i] = c[i];
			}

			long tend = System.nanoTime();

			System.out.println((tend - tstart) / 1000000000f);
		}
	}
}
