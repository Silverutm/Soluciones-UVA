def diophantine_count(a, n):
    # Dynamic Programming storage.
    # dp[i][j] is the number of ways to get a sum of exactly
    # "i", only using the "j" first terms of the equation
    dp = [[0] * len(a) for _ in range(n+1)]

    # Base case.
    # There is a single way of obtaining a sum of 0
    # (with a value of zero for all the variables)
    dp[0] = [1]*len(a)

    for i in xrange(1, n+1):
        for j, c in enumerate(a):
            # dp[j][i] can be obtained adding two sub-cases:
            # (1). using one term less (j-1), and still target the same sum (i)
            # (2). using the same terms (j), but target a (i-c) sum,
            #      where c is the coefficient of the term eliminated in (1).
            #      This is because all the solutions for (i-c) are also solutions
            #      for i by adding a c to each of them.
            s1, s2 = 0, 0
            if j > 0:
                s1 = dp[i][j-1]
            if i >= c:
                s2 = dp[i-c][j]
            dp[i][j] = s1 + s2

    return dp[n][len(a)-1]

n = int(raw_input())

for i in range(0, n):
    lista = []
    lista = list(raw_input().split())
    lista2 = []
    for x in range(0,8):
        lista2.append(int(lista[x]))

    respuesta = 0
    respuesta = diophantine_count(lista2,int(lista[8]))
    print "Equation #%d: %d" %(i+1, respuesta)