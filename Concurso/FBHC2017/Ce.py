lista = [[0]*406 for i in range(23)]
#print lista

lista[0][0] = 1
for i in range(20):	
	for j in range(401):
		if lista[i][j] != 0:
			for x in range(1,21):
				lista[i+1][j+x] += lista[i][j]


#for j in range(401):
	#print j, lista[3][j]



x = [[[0]*5 for i in range(2)] for w in range(3) ]
for i in range(3):
	for j in range(2):
		for k in range(5):
			x[i][j][k] = 1

#print x


x = [[0]*10 for i in range(10) ]
y = x
x[1][1]=3
print y[1][1]