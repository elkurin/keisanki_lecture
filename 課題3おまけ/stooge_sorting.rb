def randoms(id, size, max)
	a = Array.new(size)
	for i in 0.. size - 1
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
	for t in 0 .. 11
		size *= 2
		a = randoms(0, size, 999)
		tstart = Time.now
		sort(a, 0, size - 1)
		tend = Time.now
		puts "#{tend - tstart}"
	end
end

def sort(a, i, j)
	if a[i] > a[j]
		temp = a[i]
		a[i] = a[j]
		a[j] = temp
	end
	if j - i + 1 >= 3
		t = (j - i + 1) / 3
		sort(a, i, j - t)
		sort(a, i + t, j)
		sort(a, i, j - t)
	end
end
