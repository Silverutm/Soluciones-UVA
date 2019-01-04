#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair <int, int> ii;
typedef vector < ii > vii;

bool f(ii a, ii b)
{
	return a.first > b.first;
}

int main()
{
	int n,m,x,x0, x1,res;
	cin>>n>>m;
	--m; --n;
	vii arreglo;
	while (n--)
	{
		cin>>x;
		arreglo.push_back( ii{x, 0}  );
	}
	while (m--)
	{
		cin>>x;
		arreglo.push_back( ii{x, 1}  );
	}
	sort (arreglo.begin(), arreglo.end(),f);
	x1=x0=1;
	res=0;
	for (auto e:arreglo)
	{
		if (e.second==0)
		{
			res+=e.first*x0;
			++x1;
		}
		else
		{
			res+=e.first*x1;
			++x0;
		}
	}
	cout<<res<<endl;
	return 0;
}