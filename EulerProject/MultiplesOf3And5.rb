=begin

If we list all the natural numbers below 10 that are multiples of 3 or 5, 
we get 3, 5, 6 and 9. The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.

=end

# 3 + 6 + 9 + 12 ... + 999 = 3(1+2+3+4 ... + 333)
# 5 + 10 + 15 + 20 ... + 995 = 5(1+2+3+4 ... + 199)
# 15 + 30 + 45 + 60 ... + 999 = 15(1+2+3+4 ... + 66)

# using n(n + 1) / 2 formula, one could derive the answer:
start = Time.now

a = gets.to_i
b = gets.to_i
c = a * b
lim = gets.to_i - 1

p a*(lim/a)*(lim/a + 1)/2 + b*(lim/b)*(lim/b + 1)/2 - c*(lim/c)*(lim/c + 1)/2

p Time.now - start
=begin

#First try: 

multiplesOf1000 = []

(0...1000).each do |num|
    multiplesOf1000 << num if num % 3 == 0 || num % 5 == 0
end

p multiplesOf1000.sum


Sum of n numbers: 

1. n(n + 1) / 2

2. n(a1 + an) / 2

S1 = Sum of numbers that differ by 3
S2 = Sum of numbers that differ by 5
S3 = Sum of numbers that differ by 15 

Sum of ... by 3 or 5 = (S1 + S2) - S3 

=end