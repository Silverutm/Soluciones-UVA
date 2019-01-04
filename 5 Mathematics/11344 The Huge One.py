t = int(input())
for r in range(0,t):
    n = int(input())
    arr = [int(i) for i in input().split()]
    z = 0
    b = True
    for x in arr:
        z += 1
        if z<=1:
            continue
        if n%x:
            b=False
            break
    if b:
        print(n,"- Wonderful.")
    else:
        print(n,"- Simple.")
