import java.util.Random;

class bogo
{
	public static void main(String args[])
	{
		int size = 1;
		Random rnd = new Random();
		int a[], b[];
		a = new int [1000000];
		b = new int [1000000];

		for (int t = 0; t < 5; t++) {
			size *= 2;
			for (int i = 0; i < size; i++) {
				a[i] = rnd.nextInt(1000);
			}
			long tstart = System.nanoTime();
			while(true) {
				int k = 0;
				int check = 1;
				for (int i = 0; i < size - 1; i++) {
					if (a[i] > a[i + 1]) {
						check = 0;
						break;
					}
				}
				if (check == 1) break;
				for (int j = size; j > 1; j--) {
					int get = rnd.nextInt(j);
					b[k] = a[get];
					k++;
					a[get] = a[j - 1];
				}
				b[k] = a[0];
				for (int i = 0; i < size; i++) {
					a[i] = b[i];
				}
			}
			long tend = System.nanoTime();

			System.out.println((tend - tstart) / 1000000000f);
		}
	}
}

