#include <bits/stdc++.h>
#define pb emplace_back()
#define pair <int, int> ii;
using namespace std;
typedef long long ll;
typedef vector <int > vi;
int res[50000005];

int main()
{
	int sum =0, n, t;
	for (int i = 0;  ; ++i)
	{
		sum +=i;
		if (sum>50000000) break;
		res[sum]=i;
	}
	cin>>t;
	while (t--)
	{
		cin>>n;
		if ( res[n] ) cout<<res[n]-1<<endl;
		else cout<<"No solution\n";
	}
	return 0;
}