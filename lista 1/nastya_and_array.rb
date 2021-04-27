gets()
a = gets().split(' ').uniq
a.delete('0')
puts a.size