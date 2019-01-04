#include <bits/stdc++.h>
#define f first
#define s second
#define mk make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair <int, int> ii;
typedef pair<ll, ll> pll;
typedef vector <int> vi;
typedef vector <vi> vvi;
bool tabla[1002][1002];
int i, j, k ,l, n, m;
bool revisar()
{
	if ( ( tabla[i+1][j] and tabla[i][j+1] and tabla[i+1][j+1] ) or
	( tabla[i+1][j] and tabla[i][j-1] and tabla[i+1][j-1] ) or
	( tabla[i-1][j] and tabla[i][j-1] and tabla[i-1][j-1] ) or
	( tabla[i-1][j] and tabla[i][j+1] and tabla[i-1][j+1] ) )
		return true;
	return false;
}
main()
{
	cin>>n>>m>>k;
	for ( l = 1; l <= k; ++l)
	{
		cin>>i>>j;
		if ( tabla[i][j] ) continue;
		tabla[i][j] = true;
		if ( revisar() )
		{
			cout<<l<<endl;
			break;
		}
	}
	if (l>k) cout<<0<<endl;
	//cout<<l<<endl;
	//cout<<"gffg";
	return 0;
}