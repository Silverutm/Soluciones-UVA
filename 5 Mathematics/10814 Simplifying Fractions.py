def gcd( a, b):
    if b==0:
        return a
    return gcd(b, a%b)    

n = int(input())
for i in range(0,n):
    x = input()
    a, c, b = x.split()
    a = int(a)
    b = int(b)
    g = gcd(a, b)
    print (a // g, '/', b // g)    