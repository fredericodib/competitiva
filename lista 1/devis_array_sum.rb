gets()
arr = gets().split(' ')

sum = 0
arr.each do |elem|
  sum += elem.to_i
end

puts sum