#encoding:utf-8
from math import factorial

casos = int(raw_input())
while casos:        
    casos = casos - 1
    n = int(raw_input())
    if n==0:
        print "1"
        continue
    if n==1:
        print "x+y"
        continue
    res = "x^" +  str(n)
    for k in range(1, n):
        w = str(int( factorial(n)/factorial(k) / factorial(n - k) ))
        mm = "^" + str(n-k)
        if n-k == 1:
            mm = ""
        nn = "^" + str(k)
        if k == 1:
            nn = ""
        par = "+" + w + "x" + mm + "y" + nn
        res = res + par;
    res = res + "+y^" +  str(n)
    print res