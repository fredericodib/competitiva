ent = gets().split(' ').map {|e| e.to_i}
n =  ent[0]
k  = ent[1]

value = n
rest = n

while rest/k != 0 do
    novas_velas = rest/k
    rest = rest - novas_velas*k + novas_velas
    value += novas_velas
end


puts value