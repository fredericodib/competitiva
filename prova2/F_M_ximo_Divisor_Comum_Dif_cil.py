def mdc(num1,num2):
  if(num1%num2 == 0):
    return num2
  return mdc(num2, num1%num2);

a,b = input().split(" ")
a = int(a)
b = int(b)

res = mdc(b, a)
while (a < b and res != 1):
  a +=1
  res = mdc(a, res)

print(res)