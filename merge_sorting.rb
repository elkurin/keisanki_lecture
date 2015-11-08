def make1d(n)
	a = Array.new(n, 0)
	a
end

def merge(p, q)
	r = make1d(p.length() + q.length())
	first = 0
	second = 0
	for top in 0 .. r.length() - 1
		if first < p.length() && second < q.length()
			if p[first] < q[second]
				r[top] = p[first]
				first += 1
			else
				r[top] = q[second]
				second += 1
			end
		else 
			if first == p.length()
				r[top] = q[second]
				second += 1
			else 
				r[top] = p[first]
				first += 1
			end
		end
	end
	r
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

def mergesort(s)
	mergesort_sub(s, 0, s.length())
end

def mergesort_sub(s, a, b)
	size = b - a
	if size > 1
		mid = (a + b) / 2
		p = mergesort_sub(s, a, mid)
		q = mergesort_sub(s, mid, b)
		r = merge(p, q)
	else
		r = make1d(1)
		r[0] = s[a]
	end
	r
end

def main(n)
	for i in 1 .. 18
		a = randoms(0, 2 ** i, 999)
		tstart = Time.now
		mergesort(a)
		tend = Time.now

		puts "#{tend - tstart}"
	end
end

