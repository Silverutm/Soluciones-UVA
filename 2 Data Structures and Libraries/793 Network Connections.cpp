#include <iostream>
#include <sstream>
using namespace std;
int papa[100005], rango[100005];
int encontrar_papa(int i)
{
	return (papa[i] == i) ? i: (papa[i] = encontrar_papa(papa[i]) );
}

void unir(int i, int j)
{
	int pi = encontrar_papa(i), pj = encontrar_papa(j);
	if ( pi == pj ) return;

	if( rango[pi] > rango[pj] )
		papa[pj] = pi;
	else
	{
		papa[pi] = pj;
		if (rango[pi] == rango[pj] ) ++rango[pj];
	}
	return ;
}

int main()
{
	int casos, n, p, q, buenos, malos;
	string s;
	stringstream ss;
	char c;

	cin>>casos;	
	while (casos--)
	{
		cin>>n;
		buenos = malos = 0;
		for (int i = 1; i <= n; ++i)
		{
			papa[i] = i;
			rango[i] = 0;
		}
		getline(cin, s);
		while ( getline(cin, s) and s!="" )
		{
			ss.clear();
			ss<<s;
			ss>>c>>p>>q;
			if (c=='c') unir(p,q);
			else if ( encontrar_papa(q) == encontrar_papa(p) )
				++buenos;
			else ++malos;
		}
		cout<<buenos<<","<<malos<<"\n";
		if (casos) cout<<"\n";
	}
	return 0;
}