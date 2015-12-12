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
	for t in 0 .. 3
		size *= 2
		a = randoms(0, size, 999)
		tstart = Time.now
		bogo(a, size)
		tend = Time.now

		puts "#{tend - tstart}"
	end
end

def bogo(a, size)
	b = Array.new(size, 0)
	while true
		k = 0
		check = 1
		for i in 0 .. size - 2
			if a[i] > a[i + 1]
				check = 0
				break
			end
		end
		if check == 1
			break
		end
		for j in 0 .. size - 1 
			i = size - 1
			get = rand(200)
			b[k] = a[get]
			k++
			a[get] = a[i - 1]
		end
		b[k] = a[0]
		for i in 0 .. size - 1
			a[i] = b[i]
		end
	end
end
