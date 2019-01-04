#include <bits/stdc++.h>
#define s second
#define f first
#define mk make_pair
#define pb push_back
#define tam 305
#define INF 10000
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;

ll mod =1000000007LL;
vector<ii> AdjList[50];
int V, m, a,b,c;
int main()
{
	
	cin>>V>>m;
	while (m--)
	{
		cin>>a>>b>>c;
		a; b;
		AdjList[a].pb(mk(b,c) );
	}


	vi dist(V, INF); dist[0] = 0;
	vi pred(V, -1);
	for (int i = 0; i < V - 1; i++) // relax all E edges V-1 times
	for (int u = 0; u < V; u++) // these two loops = O(E), overall O(VE)
	for (int j = 0; j < (int)AdjList[u].size(); j++) 
	{
		ii v = AdjList[u][j]; // record SP spanning here if needed
		//dist[v.first] = min(dist[v.first], dist[u] + v.second); // relax
		if  ( dist[u] + v.second < dist[v.first])
		{
			dist[v.first] = dist[u] + v.second;
			pred[v.first] = u;
		}
	}
	for (int u = 0; u < V; u++) 
	{
		cout<<u<<": "<<dist[u]<<"    "<<pred[u]<<endl;
	}
	
	return 0;
}


