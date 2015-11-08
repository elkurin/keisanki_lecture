import java.util.Random;
class sorting
{
	public static void main(String args[])
	{
		Random rnd = new Random();
		int size = 1;
		for (int i = 0; i < 18; i++) {
			size *= 2;
			int x[];
			x = new int[1000000];
			for (int j = 0; j < size; j++) {
				x[j] = rnd.nextInt(200);
			}
			long start = System.nanoTime();
			for (int p = 0; p < size; p++) {
				for (int q = 0; q < size; q++) {
					if (x[q] > x[q + 1]) {
						int temp = x[q];
						x[q] = x[q + 1];
						x[q + 1] = temp;
					}
				}
			}
			long end = System.nanoTime();

			System.out.println((end - start) / 1000000000f);
		}
	}
}

