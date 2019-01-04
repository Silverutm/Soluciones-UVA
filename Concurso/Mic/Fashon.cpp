#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
int n=0;

string nombres[500];
set <string> sombreros[500], nolike[500];
vector < pair < string, string> > salida;
pair < string, string> ami;
bool sonamigos(int i, int j)
{
	for (auto e: sombreros[i])
		if (nolike[j].find(e)!=nolike[j].end() )
			return false;

	for (auto e: sombreros[j])
		if (nolike[i].find(e)!=nolike[i].end() )
			return false;
	return true;
}

map <string , string > mapa;

bool vistos[500];

int main()
{
	/*string s;
	getline(cin,s);
	istringstream iss(s);
	while (iss>>s)
	{
		cout<<s<<endl;
	}*/

	string s1, s2, s3;
	while (getline(cin, s1) and getline(cin, s2) and getline(cin, s3))
	{
		bool limpiar=false;
		for (auto &e: s1)
			if (e=='\'') {limpiar=true; break;}
		string s4;
		if (limpiar==false) s4=s1;
		else {
			for(auto e: s1)
				if (e!='\'') s4.pb(e);
		}
		mapa[s4]=s1;
		nombres[n]=s4;
		istringstream iss(s2);
		while (iss>>s2)
			sombreros[n].insert(s2);
		
		istringstream iss2(s3);
		while (iss2>>s3)
			nolike[n].insert(s3);
		++n;
	}
	//for (auto e:nolike[2])
		//cout<<e<<endl;
	//return 0;
	for (int i = 0; i < n; ++i)
	{
		if (vistos[i]) continue;
		for (int j = i+1; j < n; ++j)
		{
			if (vistos[j]) continue;
			if ( sonamigos(i, j) )
			{
				//ami.f=min(nombres[i], nombres[j]);
				//ami.s=max(nombres[i], nombres[j]);
				ami.f=nombres[i]; ami.s=nombres[j];
				salida.pb(ami);

				ami.f=nombres[j]; ami.s=nombres[i];
				salida.pb(ami);
				vistos[i]=vistos[j]=true;
			}

		}
	}
	sort(salida.begin(),salida.end());
	//e=min('a', 'A')-5;
	for (auto e: salida)
	{
		//for (auto k:e.f)
		//	if (k==max('z', 'Z')+5)
		//		cout<<'\'';
		//	else cout<<k;
		//cout<<" ";
		//for (auto k:e.s)
		//	if (k==max('z', 'Z')+5)
		//		cout<<'\'';
		//	else cout<<k;
		//cout<<"\n";
		cout<<mapa[e.f]<<" "<<mapa[e.s]<<"\n";
	}
	return 0;
}