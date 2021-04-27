def soma_dig(n)
    n = n.to_s
    n = n.split('')
    soma = 0
    n.each {|e| soma += e.to_i}

    return soma
end

ent = gets().split(' ').map {|e| e.to_i}
n = ent[0]
a = ent[1]
b = ent[2]

soma = 0

for i in 1..n
    soma += i if (soma_dig(i) >= a && soma_dig(i) <= b)
end

puts soma