ent = gets().to_i
names = []
position = {}

for i in 0...ent
    names << gets()
end

ordered_names = names.sort

ordered_names.each_with_index do |e, i|
    position[e] = i
end

names.each do |e|
    print position[e]
    print " "
end

print "\n"