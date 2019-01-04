#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, res, a, b, c;
	cin>>n;
	for (int i = 1; i <= n; ++i)
	{
		cin>>a>>b>>c;
		res = a + b/2 +1;
		cout<<"Scenario #"<<i<<": "<<res<<"\n";
	}
	return 0;
}