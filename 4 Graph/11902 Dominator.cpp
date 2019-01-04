#include <iostream>
#include <vector>
#include <cstring>
#define tam 105
#define pb push_back
using namespace std;
typedef vector <int> vi;

vector < vi > Lista;
bool domina[tam][tam], con[tam], sin[tam], b;

char f(bool b)
{ return b ? 'Y':'N'; }

void renglon(int n)
{
	cout<<'+';
	n= 2*n-1;
	for (int i=0; i<n; ++i) cout<<'-';
	cout<<"+\n";
}

void buqueda(int v)
{
	sin[v]=true;
	for (auto u:Lista[v])
		if (!sin[u]) buqueda(u);
}

int main()
{
	int i, j, n, caso, t;
	cin>>t;
	for (caso=1; caso<=t; ++caso)
	{
		cin>>n;
		memset(domina, false, sizeof domina);
		memset(con, false, sizeof con);
		memset(sin, false, sizeof sin);
		Lista.clear();
		Lista.resize(n+1);
		Lista[0].pb(1);
		for (i=1; i<=n; ++i)
			for (j=1; j<=n; ++j)
			{
				cin>>b;
				if ( b ) Lista[i].pb(j);
			}
		buqueda(0);
		for (i=0; i<=n; ++i) con[i]=sin[i];
		for (i=1; i<=n; ++i)
		{	
			memset(sin, false, sizeof sin);
			sin[i]=true;
			buqueda(0);
			sin[i]=false;
			for (j=1; j<=n; ++j)
				domina[i][j] = sin[j]!=con[j] ;
		}
		cout<<"Case "<<caso<<":\n";
		renglon(n);
		for (i=1; i<=n; ++i)
		{
			cout<<"|";
			for (j=1; j<=n; ++j)
				cout<<f(domina[i][j])<<"|";	
			cout<<endl;
			renglon(n);
		}
	}
	return 0;
}