#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

bool f(pair<int, int> a, pair<int, int> b)
{
	return a.second > b.second;
}

int main()
{
	int casos, n, a, parcial, total, inicio, i;
	map <int,int> mapa;
	cin>>casos;
	while (casos--)
	{
		mapa.clear();

		cin>>n;
		total = parcial = 0;
		inicio = 1;
		for ( i = 1; i <= n; ++i)
		{
			cin>>a;
			if ( mapa[a] )			
			{
				if (mapa[a] >= inicio)
				{
					parcial = i - inicio;
					total = max(total, parcial);
					inicio = mapa[a]+1;
				}
			}
			else
			{
				//++parcial;
			}
			mapa[a] = i;
		}
		total = max(total,  n+1- inicio);
		//if (parcial==0) total = n;
		
		//cout<<(*max_element(mapa.begin(), mapa.end(), f)).second<<endl;
		cout<<total<<endl;
	}
	return 0;
}