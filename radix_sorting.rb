def randoms(id, size, max)
	a = Array.new(size)
	for i in 0..(size-1)
		if max==1
			a[i]=rand()
		else
			a[i]=rand(max)
		end
	end
	a
end

def main(n)
	b = Array.new(1000000)
	size = 1
	for t in 1 .. 18
		size *= 2
		a = randoms(0, size, 999)
		tstart = Time.now
		k = 0
		c = Array.new(1000000)
		for i in 0 .. size - 1
			b[i] = a[i] % 10
		end
		for i in 0 .. 9
			for j in 0 .. size - 1
				if b[j] == i
					c[k] = a[j]
					k += 1
				end
			end
		end
		for i in 0 .. size - 1
			a[i] = c[i]
		end
		k = 0
		for i in 0 .. size - 1
			b[i] = a[i] % 100 / 10
		end
		for i in 0 .. 9
			for j in 0 .. size - 1
				if b[j] == i
					c[k] = a[j]
					k += 1
				end
			end
		end
		for i in 0 .. size - 1
			a[i] = c[i]
		end
		k = 0
		for i in 0 .. size - 1
			b[i] = a[i] / 100
		end
		for i in 0 .. 9
			for j in 0 .. size - 1
				if b[j] == i
					c[k] = a[j]
					k += 1
				end
			end
		end
		for i in 0 .. size - 1
			a[i] = c[i]
		end

		tend = Time.now

		puts "#{tend - tstart}"
	end
end
