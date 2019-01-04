lista = [ [ [0]*410 for i in range(25)] for w in range(25) ]
#lista[numero][veces][suma]
#lista[4,6,8][20][20*numero]
numero = [4, 6, 8, 10, 12, 20]

for n in numero:
	lista[n][0][0] = 1

for n in numero:
	for veces in range(20):
		for columna in range( 20*n + 1 ):
			if lista[n][veces][columna] != 0:
				for x in range(1,n + 1):
					lista[n][veces+1][columna+x] += lista[n][veces][columna]

#renglon = 16
#for n in numero:
#	for col in range(renglon, renglon*n + 1):
#		print col, lista[n][renglon][col]
#	print "\n\n\n"


renglon = 0
n = 0
h = 0
s = 0
z = 0
respuesta = 0.0



t = int(raw_input())
for caso in range(1,t + 1):
	hp, s = map(int, raw_input().split())
	cadena = raw_input()
	cadena = cadena.split(' ')
	respuesta = 0.0
	for e in cadena:
		h = hp
		uno, dos = e.split('d')
		tres = 0
		z=0
		d = dos	
		if '+' in dos:
			d, tres = dos.split('+')
			z = int( tres)
		elif '-' in dos:
			d, tres = dos.split('-')
			z = -1 * int( tres)
		
		renglon = int(uno)		
		n= int(d)		
		h -= z
		
		#print h, n, renglon, z

		total = 0
		mayor_igual = 0
		for col in range(renglon, renglon*n + 1):
			if col >= h:
				mayor_igual += lista[n][renglon][col]
			total += lista[n][renglon][col]
		parcial = mayor_igual * 1.0 / total

		respuesta =max ( respuesta, parcial )
	print "Case #{}:".format(caso),
	print '{0:.6f}'.format( respuesta )