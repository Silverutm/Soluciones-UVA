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
#define k first
#define d second
#define mk make_pair
using namespace std;
typedef long long ll;
typedef pair < int,int > ii;
typedef vector < int > vi;
typedef vector < ii > vii;
typedef vector < vi > vvi;

vvi Izq, Der;
vi entrada, tempI, tempD;
int n, tot;
bool f(int a, int b)
{ return a>b; }
int main()
{
	int i, a, j;
	vi vec;
	while (cin>>n)
	{
		entrada.clear();
		Izq.clear(); Der.clear(); tempI.clear(); tempD.clear();
		tot=0;
		for (i=0; i<n; ++i)
		{
			cin>>a;
			entrada.pb(a);
		}
		cin>>casa;
		for (auto e: entrada)
			if (e<casa) tempI.pb(e);
			else if (e>casa) tempD.pb(e);
			else ++tot;

		sort(tempI.begin(), tempI.end(), f);
		sort(tempD.begin(), tempD.end());

		vec.clear();
		for (auto e:tempI)
		{
			vec.pb(e);
			if (vec.size()==5)
			{
				 Izq.pb(vec);
				 vec.clear();
			}
		}
		if (vec.size())
			Izq.pb(vec);

		vec.clear();
		for (auto e:tempD)
		{
			vec.pb(e);
			if (vec.size()==5)
			{
				 Der.pb(vec);
				 vec.clear();
			}
		}
		if (vec.size())
			Der.pb(vec);
		//i=Izq.size()-1; j=Der.size()-1;
		//ji=jd=0;
		i=j=0;
		int pi, pd;
		while ( i<Izq.size() and j<Der.size() )
		{
			//if ( i<Izq.size() )
				pi=2*Izq[i][ Izq[i].size()-1 ] + Izq[i].size();
			//if ( j<Der.size() )
				pd=2*Der[j][ Der[j].size()-1 ] + Der[j].size();
			if (pd<pi)
			{
				++j;
				tot+=pd;
			}
			else
			{
				i++;
				tot+=pi;
			}
		}
		if (j==Der.size() )
		{
			
		}
	}
	return 0;
}