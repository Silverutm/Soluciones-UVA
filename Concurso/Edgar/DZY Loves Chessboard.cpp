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

char c1, c,ca = 'B';
int n,m;
void sig()
{
	c1 = c1 == 'B' ? 'W':'B';
}

int main()
{
	cin>>n>>m;
	for (int i = 0; i < n; ++i, cout<<endl )
	{
		c1 = ca == 'B' ? 'W':'B';
		ca = c1;
		for (int j = 0; j < m; ++j)
		{			
			cin>>c;
			if ( c=='-' ) cout<<c;
			else cout<<c1;
			sig();
		}		
	}
	return 0;
}