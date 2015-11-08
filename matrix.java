class matrix
{
	public static void main(String args[]) {
		int size = 1;
		for (int i = 0; i < 10; i++) {
			int a[][];
			a = new int[1000][1000];
			int ans[][];
			ans = new int[1000][1000];
			
			for (int j = 0; j < 1000; j++) {
				for (int k = 0; k < 1000; k++) {
					a[j][k] = 1;
					ans[j][k] = 0;
				}
			}
			long start = System.nanoTime();
			for (int p = 0; p < size; p++) {
				for (int q = 0; q < size; q++) {
					for (int r = 0; r < size; r++) {
						ans[p][q] += a[p][r] * a[r][q];
					}
				}
			}
			long end = System.nanoTime();

			System.out.println((end - start) / 1000000000f);
			size *= 2;
		}
	}
}

