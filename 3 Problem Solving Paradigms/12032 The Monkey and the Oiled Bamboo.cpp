#include <bits/stdc++.h>
using namespace std;
vector <int> diferencias;
int main()
{
	int t, n, x, ant, parcial,res;
	bool posible;
	cin>>t;
	for (int caso = 1; caso <= t; ++caso)
	{
		diferencias.clear();		

		cin>>n;
		cin>>x;
		diferencias.push_back(x);
		ant = x;
		for (int i = 1; i < n; ++i)
		{
			cin>>x;
			diferencias.push_back(x - ant);
			ant = x;
		}

		res = *max_element(diferencias.begin(), diferencias.end());
		parcial = res;

		posible = true;
		for (auto &e:diferencias)
		{
			if (e==res) --res;
			else if (e>res) {posible = false;  break; }
			//cout<<e<<" ";
		}
		//cout<<endl;

		cout<<"Case "<<caso<<": ";
		if (posible)
			cout<<parcial<<"\n";
		else cout<<parcial+1<<"\n";

	}
	return 0;
}