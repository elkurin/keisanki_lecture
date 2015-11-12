import java.util.Random;

class shell_sorting
{
	public static void main(String args[])
	{
		int a[];
		a = new int [1000000];
		int size = 1;
		Random rnd = new Random();
		for (int t = 0; t < 18; t++) {
			size *= 2;
			for (int i = 0; i < size; i++) {
				a[i] = rnd.nextInt(1000);
			}
			long tstart = System.nanoTime();
			int k = 3 * (size / 3) + 1;
			while(true) {
				while(true) {
					int check = 0;
					for (int i = 0; i < size - k; i++) {
						if (a[i] > a[i + k]) {
							int temp = a[i];
							a[i] = a[i + k];
							a[i + k] = temp;
							check = 1;
						}
					}
					if (check == 0) break;
				}
				if (k == 1) break;
				k -= 3;
			}
			long tend = System.nanoTime();
			System.out.println((tend - tstart) / 1000000000f);
		}
	}
}
