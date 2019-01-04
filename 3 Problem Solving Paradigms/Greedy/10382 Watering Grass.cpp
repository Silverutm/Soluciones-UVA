#include <iostream>
#include <cmath>
#include <algorithm>
#define f first
#define s second


using namespace std;

typedef pair <double, double> pdd;
pdd intervalos[10009];

bool fun( pdd a, pdd b )
{
	if (a.f < b.f) return true;
	else if (a.f == b.f ) return a.s > b.s ;
	return false;
}

int maxi(double inf,int i, int j)
{
	int indmaxi=i;
	if (intervalos[i].f > inf) return -1;
	while (i<j and intervalos[i].f <= inf )
	{
		if (intervalos[i].s > intervalos[indmaxi].s )
			indmaxi=i;
		++i;
	}
	return indmaxi;
}

int main()
{
	int n, i ,j, total;
	double w, l, c, r, tam, inf, sup;
	while (cin>>n>>l>>w)
	{
		for (j=i=0;i<n; ++i)
		{
			cin>>c>>r;
			if (r>w/2)
			{
				tam=sqrt( r*r-(w/2)*(w/2) );
				intervalos[j].f=c-tam;
				intervalos[j].s=c+tam;
				++j;
			}
		}
		sort (intervalos, intervalos +j, fun);
		total=0;
		inf=0;
		sup=0;
		i=0;
		while (inf < l and i<j)
		{
			i=maxi(inf, i, j);
			if (i==-1) break;
			inf= intervalos[i].s;
			++i;
			++total;
		}
		if (inf<l) cout<<-1<<endl;
		else cout<<total<<endl;
	}
	return 0;
}