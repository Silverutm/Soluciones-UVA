#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define tam 10009
using namespace std;

struct cosa
{
	int l, h;
	string s;
};

bool f(cosa a, cosa b)
{
	return a.l<b.l;
}

vector <cosa> lista;
vector <int > l;

int h[tam];
string s[tam];
int main()
{
	int t, p, q, d, i, j, a, b, cant, pos;
	string c;
	scanf("%d", &t);
	while (t--)
	{
		lista.clear(); l.clear();
		scanf("%d", &d);
		for (i=0; i<d; ++i)
		{
			cin>>c;
			scanf("%d %d", &a, &b  );
			lista.push_back( cosa{a, b, c} );
		}
		sort (lista.begin(), lista.end(), f ) ;
		i=0;
		for (auto e:lista)
		{
			s[i]=e.s;
			h[i]=e.h;
			l.push_back(e.l);
			++i;
		}
		scanf("%d", &q);
		while (q--)
		{
			scanf("%d", &p);
			auto lugar = upper_bound( l.begin(), l.end(), p );
			j = lugar - l.begin();
			if (j==l.size() ) --j;
			cant=0;
			while (j>=0 and cant!=2 )
			{
				if (p >= l[j] and p <= h[j] ) {++cant; pos=j;}
				//else if ( p<l[j] ) break;
				--j;
			}
			if (cant==1) cout<<s[pos]<<endl;
			else cout<<"UNDETERMINED\n";
		}
		if (t) cout<<endl;
	}
	return 0;
}
