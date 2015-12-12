import java.util.Random;
class insert_sorting
{
	public static void main(String args[]) {
		Random rnd = new Random();
		int size = 1;
		int a[];
		a = new int[100000000];
		for (int i = 0; i < 18; i++) {
			size *= 2;
			for (int t = 0; t < size; t++) {
				a[t] = rnd.nextInt(1000);
			}
			long start = System.nanoTime();
			for (int p = 2; p <= size; p++) {
				insert(a, p);
			}
			long end = System.nanoTime();

			System.out.println((end - start) / 1000000000f);
		}
	}

	static void insert(int a[], int size) {
		for (int j = size - 1; j >= 1; j--) {
			if (a[j] < a[j - 1]) {
				int temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			} else {
				break;
			}
		}
	}
}

