#include <bits/stdc++.h>
using namespace std;
#define tam 1000003
typedef vector <int> vi;
typedef long long ll;

int gcd(int a, int b)
{
	for (int i = 2; i < a+b; ++i)
	{
		if (a%i==0 and b%i ==0)
			return i;
	}
	return 1;
}

int main()
{
	int n;
	cin>>n;
	for (int i = 1; i <= n; ++i)
	{
		if (gcd(i,n)==1)
			cout<<i<<endl;
	}
	return 0;
}