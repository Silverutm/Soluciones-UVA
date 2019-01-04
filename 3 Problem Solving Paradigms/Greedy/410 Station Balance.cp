#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int arreglo [12], cajas[7][2];
int main()
{
	int c, s, i, caso=0, j, k;
	double promedio, imbalance;
	while (cin>>c>>s)
	{
		//if (caso) cout<<"\n";
		cout<<"Set #"<<++caso<<endl;
		promedio=0;
		for (i=0; i<s; ++i)
		{
			cin>>arreglo[i];
			promedio+=arreglo[i];
		}
		promedio /=c;
		while (i<2*c) arreglo[i++]=0;
		sort (arreglo, arreglo+ 2*c);
		k=0;
		for (i=0; i<c; ++i)
		{
			cajas[i][0]=arreglo[k];
			cajas[i][1]=arreglo[2*c-1-k];
			++k;
		}
		for (i=0; i<c; ++i)
		{	
			cout<<" "<<i<<":";
			for (j=0; j<2; ++j)
			{
				if (cajas[i][j])
					cout<<" "<<cajas[i][j];
			}
			cout<<endl;
		}
		imbalance=0;
		for (i=0; i<c; ++i)
		{
			imbalance+= fabs(cajas[i][0]+cajas[i][1]-promedio);
		}
		printf("IMBALANCE = %.5lf\n",imbalance);
		cout<<"\n";
	}
	return 0;
}