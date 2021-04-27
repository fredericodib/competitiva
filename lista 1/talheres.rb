en = gets()
en = en.split(' ')

total = 0

if (en[1].to_i > en[2].to_i)
  total = en[2].to_i
else
  total = en[1].to_i
end

total += en[3].to_i

if total.to_i > en[0].to_i
  puts en[0]
else
  puts total
end