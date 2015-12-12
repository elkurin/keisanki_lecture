def stack(n)
	a = Array.new(2 ** n, 1)
	sum = 0
	t0 = Time.now
	for i in 0 .. 2 ** n - 1
		a[i] = 1
	end
	for i in 2 ** n - 1 .. 0
		sum += a[i]
	end
	t1 = Time.now

	puts "#{(t1 - t0)}"
end

def main(n)
	i = 4
	while 2 ** i < 10000000
		stack(i)
		i += 1
	end
end 

