from math import factorial
while True:
    try:
        n = int(input())
        print (str(n) + '!')
        print (factorial(n))
    except EOFError:
        break
    