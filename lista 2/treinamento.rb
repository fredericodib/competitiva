gets()
ent = gets().split(' ').map {|e| e.to_i}

ent = ent.sort

day = 1
index = 0

while ent.size > index do
    day += 1 if day <= ent[index]
    index += 1
end

puts day - 1