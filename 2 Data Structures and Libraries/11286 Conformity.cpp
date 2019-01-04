#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n, i, maximo, total;
	map <vector <int>, int> mapa;
	vector <int> v(5);
	while (cin>>n, n)
	{
		mapa.clear();
		maximo = 0;
		while(n--)
		{
			for (int i = 0; i < 5; ++i)
				cin>>v[i];
				
			sort(v.begin(), v.end());
			//for (auto e:v)
			//	cout<<e;
			//cout<<endl;
			maximo = max(++mapa[v], maximo);
		}
		//auto fin = mapa.end();
		//fin--;
		//maximo = (*fin).second;
		//cout<<" max "<<maximo<<endl;
		total = 0;
		for (auto &e: mapa)
			if (e.second==maximo)
				total += maximo;
		cout<<total<<endl;
	}
	return 0;
}