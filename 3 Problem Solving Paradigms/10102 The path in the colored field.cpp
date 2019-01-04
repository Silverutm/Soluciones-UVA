#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#define f first
#define s second
using namespace std;
typedef pair <int , int > ii;
typedef vector < ii > vii;
vector <string> vs;
vii uno, tres;
int main()
{
	int n, i, j, maximo, minimo;
	string s;
	while (cin>>n)
	{
		vs.clear(); uno.clear(); tres.clear();
		for (i=0; i<n;++i)
		{
			cin>>s;
			vs.push_back(s);
		}
		for (i=0; i<n;++i)
			for (j=0; j<n;++j)
			{
				if (vs[i][j]=='1')
					uno.push_back(ii{i,j});
				else if (vs[i][j]=='3')
					tres.push_back(ii{i,j});
			}
		maximo=0;
		for (auto u:uno)
		{			
			minimo=3*n;
			for(auto t:tres)
				minimo=min(minimo, abs(u.s-t.s)+abs(u.f-t.f)  );
			maximo=max( maximo, minimo );		
		}
		cout<<maximo<<endl;
	}
	return 0;
}