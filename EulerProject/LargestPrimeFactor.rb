=begin

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

=end

primeFactors = []

lim = 600851475143

done = false

i = 2

while(!done)
    if lim % i == 0
        lim /= i
        primeFactors << i if !primeFactors.include?(i)
    elsif lim == 1
        done = true
    else 
        i += 1
    end
end

p primeFactors
p primeFactors.inject {|max, el| max = el if el >= max}

    
