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
	int i, a, j, casa;
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

		sort(tempI.begin(), tempI.end());
		sort(tempD.begin(), tempD.end(), f);

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
		if ( vec.size() )
			Izq.pb(vec);

		vec.clear();
		for (auto e:tempD)
		{
			vec.pb(e);
			if (vec.size()==5)
			{
				 Der.pb( vec );
				 vec.clear();
			}
		}
		if (vec.size())
			Der.pb(vec);

		//revertir();
		int subi=0, subd=0;
		for (auto v:Izq)
		{
			subi+=2*abs(v[0]-casa);
			subi +=v.size();
		}
		for (auto v:Der)
		{
			subd+=2*abs(v[0]-casa);
			subd +=v.size();
		}
		int subis=0, subds=0;
		if ( Izq.size() )
			subis=subi- abs(Izq[0][0]-casa);
			//subis=subi- abs(Izq[Izq.size()-1][0]-casa);
		if ( Der.size() )
			subds=subd- abs(Der[0][0]-casa);
			//subds=subd- abs(Der[Der.size()-1][0]-casa);

		tot += min( subd+subis, subi+subds );
		cout<<tot<<endl;
	}
	return 0;
}