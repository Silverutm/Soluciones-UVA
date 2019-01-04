#include <cstdio>
using namespace std;
int main()
{
	int t, n, arreglo[60], i, j, altos, bajos;
	scanf("%d", &t);		//número de casos
	for (i=1; i<=t; ++i)
	{
		//para cada caso hacemos lo siguiente
		scanf("%d", &n);	//numero de paredes
		for (j=0; j<n; ++j)	//alturas de las n paredes
			scanf("%d", &arreglo[j] );

		altos = bajos = 0;	//al principio Mario no ha dado 
							//saltos


		//comparamos altura de la pared j, contra la altura
		//de la pared siguiente: j+1.
		//la ultima pared no tiene siguiente, por eso j<n-1
		for (j=0; j<n-1; ++j)	
			if (arreglo[j] > arreglo [j+1])
				++bajos;
			else if (arreglo[j] < arreglo [j+1])
				++altos;

		printf("Case %d: %d %d\n",i, altos, bajos );
	}
	return 0;
}