def main(n)
	size = 1
	for t in 0 .. 17
		size *= 2
		a = randoms(0, size, 999)
		tstart = Time.now
		k = 3 * (size / 3) + 1
		check = 1
		while true
			while true
				check = 0
				for i in 0 .. size - k - 1 
					if a[i] > a[i + k]
						temp = a[i]
						a[i] = a[i + k]
						a[i + k] = temp
						check = 1
					end
				end
				if check == 0 
					break
				end
			end
			if k == 1
				break
			end
			k -= 3
		end
		tend = Time.now

		puts "#{tend - tstart}"
	end
end


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
