=begin

Each new term in the Fibonacci sequence is generated 
by adding the previous two terms. 
By starting with 1 and 2, the first 10 terms will be:

1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

By considering the terms in the Fibonacci sequence 
whose values do not exceed four million, 
find the sum of the even-valued terms.

=end

fib = []

fib << 1
fib << 2

max = 2

while(true)
    num = fib[-1] + fib[-2]
    break if num >= 4000000
    fib << num
end

sum = 0

fib.each {|el| sum += el if el % 2 == 0 }

p sum