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
	max_b = 1000
	size = 1
	b = Array.new(1000, 0)
	for t in 1 .. 17
		size *= 2
		a = randoms(0, size, 999)
		tstart = Time.now
		for i in 0 .. max_b - 1
			for j in 0 .. size - 1
				if a[j] == i
					b[i] += 1
				end
			end
		end
		k = 0
		for i in 0 .. max_b - 1
			for j in 0 .. b[i] - 1
				a[k] = i
				k += 1
			end
		end
		tend = Time.now

		puts "#{tend - tstart}"
	end
end
