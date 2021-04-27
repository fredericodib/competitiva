gets()
ent = gets().split(' ').map {|e| e.to_i}

max = ent.max()

result = 0

ent.each {|e| result += max - e}

puts result