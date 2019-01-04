#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;
map <string, int> mapa;
int main()
{
	string res, s;
	int m,n;
	while (cin>>n>>s)
	{
		mapa.clear();		
		for (int i = 0; i <= s.size() - n; ++i)
			++mapa[ s.substr(i, n) ];
		res= ""; m = 0;

		for (auto e: mapa)
			if (e.second>m)
			{
				res = e.first;
				m= e.second;
			}
		cout<<res<<endl;
	}
	return 0;
}