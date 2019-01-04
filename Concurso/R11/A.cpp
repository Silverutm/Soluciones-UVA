#include <iostream>
#include <vector>
using namespace std;

long long gcd(long long a, long long b)
{
	return b==0 ? a:gcd(b, a%b);
}

long long minimo(long long a, long long b)
{
	return a<b ? a:b;
}

long long comprimo(long long a, long long b)
{
	long long r=minimo(a,b)+1;
	while(gcd(a,r)!=1 or gcd(b,r)!=1) ++r;
	return r;
}

int main()
{
	int n, i;
	vector <long long > v, res;
	long long a;
	cin>>n;
	while (n--)
	{
		cin>>a;
		v.push_back(a);
	}
	res.push_back(v[0]);
	for (i=1; i<v.size(); ++i)
	{
		if (gcd(v[i], v[i-1])!=1)
			res.push_back(comprimo( v[i], v[i-1]) );
		res.push_back(v[i]);
	}
	cout<<res.size()-v.size()<<endl;
	n=0;
	for (auto k:res)
	{
		if (n) cout<<" ";
		n=1;
		cout<<k;
	}
	cout<<endl;
	return 0;
}