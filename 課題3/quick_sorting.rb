def quick_sort(x, left, right)
	fore = left;
	back = right;
	pivot = x[(left + right) / 2]

	while(1)
		while x[fore] < pivot
			fore += 1
		end
		while x[back] > pivot
			back -= 1
		end
		if fore >= back 
			break
		end

		temp = x[fore]
		x[fore] = x[back]
		x[back] = temp

		fore += 1
		back -= 1
	end

	if (left < fore - 1) 
		quick_sort(x, left, fore - 1)
	end
	if (back + 1 < right) 
		quick_sort(x, back + 1, right)
	end

end

def main(n)
	size = 1;
	for i in 0 .. 17
		size *= 2;
		x = Array.new(10000, 0)
		for j in 0 .. size - 1
			x[j] = rand(200)
		end
		tstart = Time.now
		quick_sort(x, 0, size - 1)
		tend = Time.now

		puts "#{tend - tstart}"
	end
end


