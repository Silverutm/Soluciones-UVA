#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
vector <int > v;
bool p=true;
int arreglo[18008];

void convertir(int r)
{
	if (arreglo[r]==0 or arreglo[r]!=v.size())
	{	
		cout<<"Signals fail to synchronise in 5 hours\n";
		return;
	}
	cout<<0<<r/3600<<":"<<r%3600/60 /10 <<r%3600/60 %10<<":"
		<<r%3600%60 /10<<r%3600%60 %10<<endl;
}

void solve()
{
	if ( v.empty() )
	{
		p=false;
		return ;
	}
	memset (arreglo, 0, sizeof arreglo);
	for (auto& e: v)
	{
		bool p1=true;
		for (int i=0; p1; i+=2)
			for (int x=0; x<e-5 and p1; ++x)
				if (i*e+x > 18000) p1=false;
				else ++arreglo[e*i+x];
	}
	//cout<<*max_element(v.begin(), v.end() )-6<<endl;
	if (*max_element(v.begin(), v.end() )-5>18000) 
	{
		cout<<"Signals fail to synchronise in 5 hours\n";
		v.clear();
		return ;
	}
	int r=max_element(arreglo+*min_element(v.begin(), v.end() )-5, arreglo+18001)-arreglo;
	convertir(r);
	v.clear();
}
int main()
{
	int n;
	while (cin>>n, p)
	{
		if (n==0)
			solve();
		else v.push_back(n);
	}
	return 0;
}