from math import factorial
n = int(input())
while n:        
    print (str(n) + '! --')
    x = str( factorial(n) )    
    num = [0]*500
    for c in x:
        num[int(c)] += 1
    ca = 30
    #print("%3d" %(ca) )
    #print ("   (0)%5d(1)%5d(2)%5d(3)%5d(5)%5d".format(num[0],num[1],num[2],num[3],num[5]) )
    print ("   (0){:5d}    (1){:5d}    (2){:5d}    (3){:5d}    (4){:5d}".format(num[0],num[1],num[2],num[3],num[4]) )
    print ("   (5){:5d}    (6){:5d}    (7){:5d}    (8){:5d}    (9){:5d}".format(num[5],num[6],num[7],num[8],num[9]) )
    #print ("\t(5)\t" + str(num[5]) +  "\t(6)\t" + str(num[6]) +  "\t(7)\t" + str(num[7]) +  "\t(8)\t" + str(num[8]) +  "\t(9)\t" + str(num[9]) ) 
    n = int(input())
    