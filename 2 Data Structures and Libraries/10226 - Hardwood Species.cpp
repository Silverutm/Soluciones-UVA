#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
int main()
{
	int t, contador;
	string s;
	map <string , int> mapa;
	cin>>t;
	getline(cin,s);
	getline(cin,s);
	while(t--)
	{
		mapa.clear();
		contador=0;
		while (getline(cin,s) and s.size())
		{
			//cout<<s<<endl;
			mapa[s]++;
			++contador;
			//s="";
		}	
		for (auto par:mapa)
		{	cout<<par.first;
			printf(" %.4f\n", par.second*100/(float)contador );
		}
		if (t) printf("\n");
	}
	return 0;
}
