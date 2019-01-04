#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define pb push_back
using namespace std;
typedef vector <int> vi;
typedef vector < vi > vvi;
int N, n;
vvi tamk;
vi entrada;
vi sol;
void todos(int k)
{
	if (entrada.size()==n)
	{
		tamk.pb(entrada);
		return;
	}
	if (k>N)
		return;
	for (int i=k; i<=N; ++i)
	{
		entrada.pb(i);
		todos(i+1);
		entrada.pop_back();
	}
}

bool esta(vi e, vi v)
{
	bool r=true, parical;
	for (int i=1; i<e.size() and r; ++i)
	{
		parical=false;
		for (auto v1:v)
			if (v1==e[i])
				parical=true;
		r=parical;
	}	
	return r;
}

int main()
{
	int i, m, a, t, respuesta, parical, caso=0;
	vvi Subs;
	while (cin>>N>>n and (N or n) )
	{		
		//cout<<N<<" "<<n<<endl;
		tamk.clear();
		Subs.clear();
		for (i=0; i<N; ++i)
		{
			entrada.clear();
			cin>>a;
			entrada.pb(a);entrada.pb(i+1);
			Subs.pb(entrada);
		}
		cin>>m;
		for (i=0; i<m; ++i)
		{
			cin>>t;
			entrada.clear();
			entrada.pb(1);
			while(t--)
			{
				cin>>a;
				entrada.pb(a);
			}
			cin>>a; entrada[0]=a;
			Subs.pb(entrada);	
		}
		//return 0;
		//m+=N;
		entrada.clear();
		todos(1);
		//continue;
		//return 0;
		sol.clear();
		respuesta=0;
		for (auto v:tamk)
		{
			parical=0;
			for (auto e:Subs)
			{
				if ( esta(e, v) )
				{
					if (e.size()%2)
						parical-=e[0];
					else parical+=e[0];
				}
			}
			if (parical>respuesta)
			{
				respuesta=parical;
				sol=v;
			}
			//respuesta=max(respuesta, parical);
		}
		printf("Case Number  %d\n", ++caso);
		printf("Number of Customers: %d\n",respuesta );
		printf("Locations recommended:");
		for (auto e: sol)
			cout<<" "<<e;
		cout<<endl<<endl;

		//cout<<respuesta<<endl;

	}
	return 0;
}