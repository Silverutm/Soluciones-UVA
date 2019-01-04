import sys
n=1
#for line in sys.stdin:
while n<30:
    #n, m = line.split()
    #n = int(n)
    #m = int(m)      
    m = n
    res = 1
    i = 0
    while i<m:
        res = res * ( n - i)
        while res%10==0:
            res /= 10
        i = i + 1
    print (res%10)
    n += 1