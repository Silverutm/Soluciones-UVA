import sys
z = [0]
pos = [0]
neg = [0]
for line in sys.stdin:
    arr = [int(i) for i in line.split()]    
    z = z + arr
    if arr[-1]!=-999999:         
        continue
    ultimo = len(z) - 2
    pos = [0]*(ultimo + 1)
    neg = [0]*(ultimo + 1)
    for i in range(1, ultimo + 1):        
        if z[i]>0:
            if pos[i - 1] != 0:
                pos[i] = pos[i - 1] * z[i]
            else:
                pos[i] = z[i]
            neg[i] = neg[i - 1] * z[i]
        elif z[i]<0:
            if pos[i - 1] != 0:
                neg[i] = pos[i - 1] * z[i]
            else:
                neg[i] = z[i]
            pos[i] = neg[i - 1] * z[i]
    
    if z[1]<0:
        del pos[1]
    del pos[0]
    del neg[0]
    m = len(pos)
    res = 0
    if m>0:
        res = max(neg + pos)
    else:
        res = max(neg)
    print (res)
    

    
    #print(z)    
    z = [0]