#include <bits/stdc++.h>
using namespace std;
#define tam 500007
typedef vector <int> vi;
typedef long long ll;
set <int> miset;
list<int> lista;
int main()
{
	for (int i = 0; i < 50; ++i)
	{
		miset.insert(i);
		lista.push_back(i);
	}
	//auto j = miset.find(15) - miset.begin();
	
	cout<<lista[3]<<"\n";
	//cout<<j<<"\n";
}