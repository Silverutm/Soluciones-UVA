#include <iostream>
#include <vector>
#include <algorithm>

#define mk make_pair
#define fi first
#define se second
#define pb push_back

using namespace std;

typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector < ii > vii;

vector < vii > ListAdj;
vector < pair <int, ii > > Aristas;
vi visitado;

void busquedaprof(int v)
{
	visitado[v]=true;
	int u;
	for (int i=0; i<ListAdj[v].size(); ++i)
	{
		u=ListAdj[v][i].fi;
		if (not visitado[ u ] )
			busquedaprof( u );
	}
	return ;
}

bool f(pair <int, ii > a, pair <int, ii > b)
{ return a>b; }

int main()
{
	int i, j, m, n, w, a, b;
	cin>>n>>m;
	ListAdj.clear();
	ListAdj.resize(n+1);
	while (m--)
	{
		cin>>a>>b>>w;
		Aristas.pb( mk(w, mk(a,b) ) );
		ListAdj[a].pb( mk(b,w) );
		ListAdj[b].pb( mk(a,w) );
	}
	cout<<"Lista de adyacencia VECINOS\n";
	for (i=1; i<=n; ++i )
	{
		cout<<i<<":";
		for (j=0; j<ListAdj[i].size(); ++j)
			cout<<" "<<ListAdj[i][j].fi;
		cout<<endl;
	}
	cout<<endl<<endl;

	cout<<"Lista de adyacencia PESOS\n";
	for (i=1; i<=n; ++i )
	{
		cout<<i<<":";
		for (j=0; j<ListAdj[i].size(); ++j)
			cout<<" "<<ListAdj[i][j].se;
		cout<<endl;
	}
	cout<<endl<<endl;

	sort (Aristas.begin(), Aristas.end(), f);
	cout<<"Lista Aristas\n";
	for (auto x:Aristas)
		cout<<x.fi<<" "<<x.se.fi<<" "<<x.se.se<<endl;
	cout<<endl<<endl;

	visitado.resize(n+1);
	int s, t;
	cin>>s>>t;
	busquedaprof( s );
	cout<<s<<" "<<t<<": ";
	if ( visitado[t] ) cout<<"Si\n";
	else cout<<"No\n";

 	return 0;
}