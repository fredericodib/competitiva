en = gets().split(' ')
m = []

for i in 0...en[0].to_i
  m << gets().split('')
end

col_primeiro = -1
col_ultimo = -1
row_primeiro = -1
row_ultimo = -1

m.each_with_index do |line, row_i|
  for col_i in 0...en[1].to_i
    elem = line[col_i]
    if elem == '1'
      if col_primeiro == -1
        col_primeiro = col_i
        col_ultimo = col_i
      elsif col_i > col_ultimo
        col_ultimo = col_i
      elsif col_i < col_primeiro
        col_primeiro = col_i
      end

      if row_primeiro == -1
        row_primeiro = row_i
        row_ultimo = row_i
      elsif row_i > row_ultimo
        row_ultimo = row_i
      elsif row_i < row_primeiro
        row_primeiro = row_i
      end
    end
  end
end

largura = col_ultimo - col_primeiro
altura = row_ultimo - row_primeiro

if col_primeiro != -1
  largura += 1
  altura += 1
end

puts "#{largura}x#{altura}"