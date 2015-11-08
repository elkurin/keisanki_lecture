def insert_sort(a, size)
	for i in 1 .. size - 1
		j = size - i
		if a[j] < a[j - 1]
			 temp = a[j]
			 a[j] = a[j - 1]
			 a[j - 1] = temp
		else
			break
		end
	end
end

def randoms(id, size, max)
	a = Array.new(size)
	for i in 0 .. size - 1
		if max == 1
			a[i]=rand()
		else
			a[i]=rand(max)
		end
	end
	a
end

def main(n)
	size = 1
	for i in 0 .. 17
		size *= 2
		x = randoms(0, size, 999)
		tstart = Time.now
		for p in 2 .. size
			insert_sort(x, p)
		end
		tend = Time.now

		puts "#{tend - tstart}"
	end
end

