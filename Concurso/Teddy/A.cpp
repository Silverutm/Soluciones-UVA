#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
long long c, arreglo[5005], p, t;
int i, ip;
void solucion()
{
	vector<long long > menor, igual, mayor;
	bool imprimi=false;
	for (i=0; i<t; ++i)
		if (arreglo[i]<p) menor.push_back(arreglo[i]);
		else if (arreglo[i]>p) mayor.push_back(arreglo[i]);
		else igual.push_back(arreglo[i]);

	for (i=0; i<menor.size(); ++i)
	{
		if (i) printf(" " );
		printf("%lld", menor[i]);
		imprimi=true;
	}

	if (imprimi && igual.size() ) printf(" ");
	for (i=0; i<igual.size(); ++i)
	{
		
		if (i) printf(" " );
		printf("%lld", igual[i]);
		imprimi=true;
	}

	if (imprimi && mayor.size() ) printf(" ");
	for (i=0; i<mayor.size(); ++i)
	{
		
		if (i) printf(" " );
		printf("%lld", mayor[i]);
	}
	printf("\n");
}

int main()
{
	
	freopen("data.out", "w", stdout);
	freopen("data.in", "r", stdin);
	cin>>c;
	while (c--)
	{
		cin>>t;
		cin>>ip;
		for (i=0; i<t; ++i)
			cin>>arreglo[i];
		p=arreglo[ip];
		solucion();
	}

	return 0;
}