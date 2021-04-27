num = gets().to_i

bills = 0

bills += (num/100).to_i
num = num%100

bills += (num/20).to_i
num = num%20

bills += (num/10).to_i
num = num%10

bills += (num/5).to_i
num = num%5

bills += (num/1).to_i
num = num%1

puts bills