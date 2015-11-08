class stack
{
	public static void main(String args[]) {
		int size = 16;
		while(size < 1000000000) {
			do_stack(size);
			size *= 2;
		}
	}
	static void do_stack(int size) {
		int a[];
		a = new int[size];
		int sum = 0;
		long start = System.nanoTime();
		for (int i = 0; i < size; i++) {
			a[i] = 1;
		}
		for (int i = size - 1; i >= 0; i--) {
			sum += a[i];
		}
		long end = System.nanoTime();
		System.out.println((end - start) / 1000000000f);
	}
}
