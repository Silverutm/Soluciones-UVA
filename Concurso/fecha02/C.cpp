#include <bits/stdc++.h>
#define tam 100005
using namespace std;
bitset<tam> casas;
int n, k, r;
int main()
{	
	int pos, contador, i, total=0;
	scanf("%d %d %d", &n, &k, &r);
	for ( i = 0; i < k; ++i)
	{
		scanf("%d", &pos);
		casas[pos] = true;
	}

	contador = 0;
	for ( i = 0; i < r-1; ++i)
		contador += casas[i];

	for (; i < n; ++i)
	{
		contador += casas[i];
		if (contador==0)
		{
			casas[i] = true;
			contador = 1;
			++total;
		}
		if (contador==1)
		{
			if (casas[i])
				casas[i-1] = true;
			else casas[i] = true;
			contador = 2;
			++total;
		}
		contador -= casas[i-r+1];
	}
	printf("%d\n", total);
	return 0;
}