from math import factorial
f = [0]*305
f[0] = 1
for n in range(1, 301):
    res = 0
    for i in range(0,n):
        res += f[i] * f[n - 1 - i]
    f[n] = res


n = int(input())
while n>0:
    print (factorial(n)*f[n])
    n = int(input())
    