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
int main()
{
	int n, da=0, df = 0;
	bool nb, na;
	cin>>n;
	if ( n%400==0 or ( n%4==0 and n%100!=0 ) )
	{
		nb=true;
		df = ( da + 1 ) % 7;
	}
	else nb = false;
	do
	{
		++n;
		da = ( df + 1 ) % 7;
		if ( n%400==0 or ( n%4==0 and n%100!=0 ) )
		{
			
			df = ( da + 1 ) % 7;
			na =  true;
		}
		else
		{
			 df = da;
			 na = false;
		}
	}while ( da or nb!=na );
	cout<<n<<endl;
	return 0;
}