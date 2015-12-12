import java.util.Random;

class merge_sorting
{
	static void merge(int a[], int start, int end)
	{
		int b[];
		b = new int [1000000];
		int size = end - start + 1;
		int mid = (start + end) / 2;
		if (size > 2) {
			merge(a, start, mid);
			merge(a, mid + 1, end);
		}
		int one, two, top;
		one = start;
		two = mid + 1;
		top = start;

		while(true) {
			if (a[one] < a[two]) {
				b[top] = a[one];
				top++;
				one++;
				if (one > mid) {
					for (int i = two; i <= end; i++) {
						b[top] = a[i];
						top++;
					}
				}
			} else {
				b[top] = a[two];
				top++;
				two++;
				if (two > end) {
					for (int i = one; i <= mid; i++) {
						b[top] = a[i];
						top++;
					}
				}
			}
			if (top > end) break;
		}
		for (int i = start; i <= end; i++) {
			a[i] = b[i];
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
			for (int j = 0; j < size; j++) {
				a[j] = rnd.nextInt(1000);
			}
			long start = System.nanoTime();
			merge(a, 0, size - 1);
			long end = System.nanoTime();

			System.out.println((end - start) / 1000000000f);
		}
	}

}
