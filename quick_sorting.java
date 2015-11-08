import java.util.Random; 
class quick_sorting
{
	public static void main(String args[])
	{
		Random rnd = new Random();
		int x[];
		x = new int[1000000];
		int size = 1;
		for (int j = 0; j < 18; j++) {
			size *= 2;
			for (int p = 0; p < size; p++) {
				x[p] = rnd.nextInt(200);
			}
			double tstart = System.nanoTime();
			sort(x, 0, size - 1);
			double tend = System.nanoTime();

			System.out.println((tend - tstart) / 1000000000f);
		}
	}
			

	static void sort(int x[], int start, int end)
	{
		int fore = start;
		int back = end;
		int pivot = x[(start + end) / 2];

		while(true) {
			while(x[fore] > pivot) fore++;
			while(x[back] < pivot) back--;
			if (fore >= back) break;

			int temp = x[fore];
			x[fore] = x[back];
			x[back] = temp;

			fore++;
			back--;
		}

		if (start < fore - 1) sort(x, start, fore - 1);
		if (back + 1 < end) sort(x, back + 1, end);
	}
}
