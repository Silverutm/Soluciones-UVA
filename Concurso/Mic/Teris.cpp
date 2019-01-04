#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;

int lejos[25009];

int main()
{
	string s, p, s1, s2;
	int tam=0;
	getline (cin, s);
	//getline (cin, s1);
	//if (s2==s1) cout<<"mocos";
	//return 0;
	do
	{
		p.push_back(s[tam]);
		bool posible=true;
		int i, k, j;
		for ( i = p.size(); i <= s.size() - p.size() and posible; i+=p.size())
		{
			for (j=i, k=0; j<i+p.size() and posible; ++j, ++k)
				if (p[k]!=s[j]) posible=false;
			if (posible) lejos[tam]++;
		}
		//if (lejos[tam])
		//	lejos[tam]=i;
		++tam;
	} while (p.size()< s.size()/2);
	tam= max_element(lejos, lejos+p.size())- lejos;
	//cout<<tam;
	string w;
	int cuenta=0;
	for (int i = 0; i <= tam; ++i)
	{
		w.pb(s[i]);
		//if (s[i]=='*') cuenta++;
	}
	//int cuenta=0;
	//int k, j;
	//for ( i = p.size(); i <= s.size() - p.size() and posible; i+=p.size())
	//	{
	//		for (j=i, k=0; j<i+p.size() and posible; ++j, ++k)
	//			if (p[k]!=s[j]) posible=false;
	//		if (posible) ++cuenta;
	//	}
	//cout<<(lejos[tam])/(tam+1)<<"\n"<<w<<"\n";
	//	cout<<cuenta+1<<endl<<w<<endl;
	cout<<lejos[tam]+1<<endl<<w<<endl;
	return 0;
}