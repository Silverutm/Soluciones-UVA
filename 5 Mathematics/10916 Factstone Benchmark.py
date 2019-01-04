from math import factorial
n = int(input())
while n>0:
    n = n - n%10
    n = n - 1960
    n = n / 10
    po = 2 ** ( 4*(2**n) )
    #print (po, n)
    print (n)
    x = 0
    res = 0
    while factorial(x) <= po:
        res = x
        x += 1
    print (res)
    n = int(input())
    