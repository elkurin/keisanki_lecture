include(Math)

def make_matrix(a, b)
	x = Array.new(a){ Array.new(b, 1) }
end


def matrix(n)
	for j in 0..9 do
		size = 2 ** j
		x = make_matrix(size, size)
		y = make_matrix(size, size)
		
		ans = make_matrix(size, size)

		t0 = Time.now

		for p in 0..size-1 do
			for q in 0..size-1 do
				sum = 0
				for i in 0..size-1 do
					sum += x[p][i] * y[i][q]
				end
				ans[p][q] = sum;
			end
		end

		t1 = Time.now

		puts "#{(t1 - t0)}"
	end
end

	
