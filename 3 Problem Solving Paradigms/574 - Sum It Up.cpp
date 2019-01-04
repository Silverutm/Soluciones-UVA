#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
set < vector<int> > miset;
int t, n, arreglo[20];
bool b;

bool myfunction (int i,int j) { return (i>j); }

void resolver(int i, int suma, vector <int> candidato)
{
	if (i>n) return;
	if (suma>t) return;
	if (suma==t)
	{
		if (miset.find(candidato)!=miset.end() ) return;

		for (int z=0; z<candidato.size(); ++z)
		{
			printf("%d", candidato[z]);
			if (z!=candidato.size()-1 ) printf("+");
		}
		printf("\n");
		b=true;
		miset.insert( candidato);
		return;
	}
	candidato.push_back( arreglo[i] );
	resolver(i+1, suma+ arreglo[i] , candidato);
	candidato.pop_back();
	resolver(i+1, suma, candidato);
}

int main()
{
	int i;
	vector <int> vacio;
	while (scanf("%d %d", &t, &n), n)
	{
		for (i=0; i<n; ++i)
			scanf("%d", &arreglo[i] );
		sort (arreglo, arreglo +n, myfunction);

		printf("Sums of %d:\n", t);
		b=false;
		resolver(0, 0, vacio);
		if (b==false)
			printf("NONE\n");
	}
	return 0;
}