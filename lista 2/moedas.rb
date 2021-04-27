ent = gets().split(' ').map {|e| e.to_i}
n = ent[0]
a = ent[1]

puts a >= n%500 ? 'Sim' : 'Nao'