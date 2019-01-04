#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <vector>
#include <bitset>
#include <map>
#include <cmath>
#include <queue>
#define f first
#define s second
#define mk make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair <int, int> ii;
typedef pair<ll, ll> pll;
typedef vector <int> vi;
typedef vector <vi> vvi;
bool matriz[105][100003];
vi Lista;
ii par, fin;
int x[]={0,1,0,-1}, y[]={-1,0,1,0};

int n, m;
int buscar()
{
	queue < pair<ii, int> > cola;
	cola.push(mk(par,0));
	while (1)
	{
		auto p=cola.front(); cola.pop();
		if (p.f==fin) return p.s;		
		for (int i=0; i<4; ++i)
		{
			auto copia=p;
			copia.f.f=p.f.f+y[i];
			copia.f.s=p.f.s+x[i];

			if (copia.f.f<1) copia.f.f=1;
			else if (copia.f.f>n) copia.f.f=n;
			//if (copia.f.s> Lista[copia.f.f] ) 

			if (copia.f.s<1) copia.f.s=1;
			else if (copia.f.s>Lista[copia.f.f]+1) copia.f.s=Lista[copia.f.f]+1;
			//if (validar(p, i) )
			if (matriz[copia.f.f][copia.f.s]==0)
			{
				cola.push(mk( mk(copia.f.f, copia.f.s) ,p.s+1));
				matriz[copia.f.f][copia.f.s]=1;
			}
		}
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);
	cin>>n;
	int x1,x2,y1,y2, a;
	Lista.pb(1);
	m=n;
	while (m--)
	{ cin>>a; Lista.pb(a); }
	cin>>y1>>x1>>y2>>x2;
	matriz[y1][x1]=1;
	ii p(y1,x1), fi(y2, x2);
	fin =fi; par=p;
	//if (y1==y2) cout<<abs(x1-x2)<<endl;	
	cout<<buscar()<<endl;
	return 0;
}