#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector < pair <int, int> > botontop;
pair <int, int> p;
int main()
{
	int n, contador, puntos, i;
	while (cin>>n)
	{
		botontop.clear();
		while (n--)
		{
			cin>>p.second>>p.first;
			p.first=-p.first;
			p.second=-p.second;
			botontop.push_back(p);
		}
		sort(botontop.begin(), botontop.end());
		contador=1;
		i=puntos=0;
		while(contador and i<botontop.size() )
		{
			--contador;
			puntos-=botontop[i].second;
			contador-=botontop[i].first;
			++i;
		}
		cout<<puntos<<endl;

	}
	return 0;
}
