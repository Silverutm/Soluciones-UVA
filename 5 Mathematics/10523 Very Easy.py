import sys
for line in sys.stdin:
    n, a = line.split()
    n = int(n)
    a = int(a)
    i = 1      
    res = 0  
    while i<=n:
        res += i * (a ** i)
        i += 1
    print (res)