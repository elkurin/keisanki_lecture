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

def selsort(s)
	for i in 0 .. s.length() - 2
		for j in i + 1 .. s.length() - 1
			if s[i] > s[j] 
				temp = s[i]
				s[i] = s[j]
				s[j] = temp
			end
		end
	end
	s
end

def main(n)
	for t in 1 .. 18
		a = randoms(0, 2 ** t, 1000)
		tstart = Time.now
		selsort(a)
		tend = Time.now

		puts "#{tend - tstart}"
	end
end
