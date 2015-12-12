def randoms(id, size, max)
	a = Array.new(size)
	for i in 0.. size - 1
		if max == 1
		  a[i] = rand()
		else
		  a[i] = rand(max)
		end
	end
	a
end

def change(i, r, a)
	keep = a[i]
	while true
		j = 2 * i + 1
		if j > r 
			break
		end
		if j < r
			if a[j + 1] > a[j]
				temp = a[j]
				a[j] = a[j + 1]
				a[j + 1] = temp
			end
		end
		if keep >= a[j]
			break
		end
		a[i] = a[j]
		i = j
	end
	a[i] = keep
end

def heap_sort(a, size)
	for i in 1 .. size / 2
		change(size / 2 - i, size - 1, a)
	end
	for i in 1 .. size - 1
		temp = a[0]
		a[0] = a[size - i]
		a[size - i] = temp
		change(0, size - i - 1, a)
	end
end

def main(n)
	size = 1
	for t in 1 .. 18
		size *= 2
		a = randoms(0, size, 999)
		tstart = Time.now
		heap_sort(a, size)
		tend = Time.now

		puts "#{tend - tstart}"
	end
end

