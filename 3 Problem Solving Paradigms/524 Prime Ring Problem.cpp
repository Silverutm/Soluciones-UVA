#include <bits/stdc++.h>
using namespace std;

vector <int> Lista[20], v;
vector <vector <int>> sol[20];
int primos[]={2,3,5,7,11,13, 17, 19, 23, 29,31};
bitset<40> esprimo, visitado;


void buscar(int e)
{
	if (e==1)
	{
		if ( *max_element(v.begin(), v.end()) == v.size() )
			sol[v.size()].push_back(v);
		return;
	}
	if (visitado[e]) return;
	v.push_back(e);
	visitado[e] = true;
	for (auto & u: Lista[e])		
			buscar(u);
	v.pop_back();
	visitado[e] = false;
}

int main()
{
	for (auto &e:primos)
		esprimo[e]=true;
	for (int i = 1; i < 17; ++i)
		for (int j = i+1; j < 17; ++j)
			if (esprimo[i+j])
			{
				Lista[i].push_back(j);
				Lista[j].push_back(i);
			}

	v.push_back(1);
	visitado[1] = true;
	for (auto e:Lista[1])
		buscar(e);

	int n, caso=1;
	while (cin>>n)
	{
		if (caso>1) cout<<"\n";
		cout<<"Case "<<caso++<<":\n";
		for( auto ve:sol[n])
		{
			cout<<ve[0];
			for (int i = 1; i < n; ++i)
				cout<<" "<<ve[i];
			cout<<"\n";

		}		
	}
	return 0;
}