#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <queue>
using namespace std;
int arreglo[100000009];


long long minimo(long long a, long long b)
{
	return a<b ? a:b;
}

vector <int> tri;
set <int> miset;
queue <pair<int, int> > cola; //ele, it
map <int, int> mapa;

int r, k;

int f(int i)
{
	 k= mapa[ r=*miset.upper_bound(i) ];
	r-=k;
	--k;
	return r;
}

int busqueda()
{
	int num= cola.front().first;
	if (arreglo[num]) return arreglo[num];
	while (1)
	{
		 num= cola.front().first;
		int res=cola.front().second;
		if (num==0) return res;
		cola.pop();
		f(num);
		for (int i=0; i<tri.size(); ++i)
		{
			if (num-tri[i]<0) break;
			cola.push(make_pair(num-tri[i], res+1) );
		}
	}

}

int main()
{
	int temp=10000009, i;
	//for (i=1; i<=temp; i+=2)
	//	raiz[i*i]=i;
	int  sum=0;

	for (i=1; sum<=temp; ++i)
	{
		
		
		arreglo[sum]=1;
		tri.push_back(sum);
		miset.insert(sum);
		mapa[sum]=i;
		sum+=i;
	}
	

	while( scanf("%d", &i)==1 )
	{
		while (!cola.empty()) cola.pop();
		cola.push( make_pair(i, 0) );
		printf("%d\n",arreglo[i]= busqueda() );
	}

		

	return 0;
}