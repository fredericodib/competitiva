def is_diferent(year)
    str = year.to_s
    str = str.split('')
    return str.size != str.uniq.size
end

ent = gets().to_i
ent += 1

while is_diferent(ent) do
    ent += 1
end

puts ent


