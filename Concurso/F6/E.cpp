#include <iostream>
#include <algorithm>
#include <set>
#include <bitset>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <vector>
#include <queue>

#define pb push_back
#define f first
#define s second
#define mk make_pair
using namespace std;
typedef pair <int, int> ii;
typedef vector < int > vi;
typedef vector < ii > vii;
typedef vector < vi > vvi;
typedef long long ll;

vi Lista[105];
int n, m, s ,t;
ll cuantos[105], despues[105];
bool noestaenlacola[105];
void buscar()
{
	queue < ii > cola;
	while (!cola.empty()) cola.pop();
	cola.push(mk(s,0));
	
	ii p;
	int tem=0;

	for (int i=0; i<n;++i)
		{
			noestaenlacola[i]=true;
			cuantos[i]=0;
			despues[i]=0;
		}
	cuantos[s]=1;
	while (!cola.empty() and cola.front().s!=t)
	{
		while (!cola.empty() and cola.front().s==tem)
		{
			p=cola.front(); cola.pop();
			for (auto v:Lista[p.f])
			{
				despues[v]+=cuantos[p.f];
				if (noestaenlacola[v])
				{
					cola.push(ii{v,p.s+1});
					noestaenlacola[v]=false;
				}
			}
		}
		for (int i=0; i<n;++i)
		{
			noestaenlacola[i]=true;
			cuantos[i]=despues[i];
			despues[i]=0;
		}
		++tem;
		//ll res=0;
	//for (int i=0; i<n; ++i)
	//	res+=cuantos[i];
	//cout<<res<<endl;
	}
}
int a, b;
int main()
{
	while (cin>>n>>m>>s>>t)
	{
		for (int i=0; i<n; ++i )
			Lista[i].clear();
		while (m--)
		{
			cin>>a>>b;
			Lista[a].pb(b);
			Lista[b].pb(a);
		}
		memset(cuantos, 0, sizeof cuantos);
		buscar();
		ll res=0;
	for (int i=0; i<n; ++i)
		res+=cuantos[i];
	cout<<res<<endl;
	}
	
	return 0;
}
