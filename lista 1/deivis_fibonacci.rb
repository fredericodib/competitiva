def fibonacci(num)
  if num == 0 ||  num == 1
    return num
  end

  return fibonacci(num-1) + fibonacci(num-2)
end

puts fibonacci(gets().to_i)