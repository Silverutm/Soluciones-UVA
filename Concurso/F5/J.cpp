#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <set>
#define pb push_back
#define mk make_pair
#define f first
#define s second
using namespace std;
typedef pair <int, int> ii;
typedef vector < int > vi;
typedef vector < ii > vii;
typedef long long ll;
vi base, s;
int respuesta[105];

vi cosa(int i)
{
	int w;
	vi h;
	for (w=0; w<i; ++w)
		h.pb(s[w]);
	for (++w; w<s.size(); ++w)
		h.pb(s[w]);
	return h;
}

int main()
{
	cout<<"#\n";
	//return 0;
	bool b;
	int i, k;
	memset(respuesta, -1, sizeof respuesta);
	for (i=1; i<=100; ++i)
		base.pb(i);
	
	for (k=1; k<=1000;++k)
	{
		//cout<<k<<"hola\n";
		s=base;
		i=0;
		b=true;
		//cout<<s.size()<<endl;
		//continue;
		for (int w=0; w<99; ++w)
		{
			
			if (i<0)
			{
				cout<<"--------\n"<<i<<"\n-----\n";
				break;
			}
			if (b)
			{
				i=(i+k-1)%s.size();
				//s.pop_back();
				//s.erase(s.begin()+i);
				s=cosa(i);
				i %=s.size();
			}
			else 
			{
				i=((i-(k-1))%(int)s.size()+(int)s.size())%s.size();
				//s.pop_back();
				//s.erase(s.begin()+i);
				s=cosa(i);
				i=i+s.size()-1;
				i %=s.size();	
			}
			//cout<<k<<" "<<s.size()<<" "<<i<<endl;
			//break;
			b = !b;
		}
		if (respuesta[ s[0] ]==-1)
			respuesta[ s[0] ]=k;
	}

	for (i=1; i<=100; ++i)
		cout<<i<<" "<<respuesta[i]<<endl;
	for (i=1; i<=100; ++i)
		cout<<", "<<respuesta[i];
	return 0;
}