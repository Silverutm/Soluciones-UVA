#include <iostream>
#include <algorithm>
using namespace std;
long long arreglo[10009];
int n, m;

bool f(long long a, long long b)
{
	//return a>b;
	if (a%m < b%m) return true;
	else if (a%m == b%m)
	{
		if (a%2==0 and b%2==0)
		{
			if (a<b) return true;
			return false;
		}
		else if (a%2 and b%2)
		{
			if (a>b) return true;
			return false;	
		}
		else
		{
			if (a%2) return true;
			return false;
		}

	}
	return false;
}

int main()
{
	int i;	
	while (cin>>n>>m and (n or m))
	{
		cout<<n<<" "<<m<<endl;
		for (i=0; i<n; ++i)
			cin>>arreglo[i];
		sort(arreglo, arreglo+n, f);
		for (i=0; i<n; ++i)
			cout<<arreglo[i]<<endl;
	}
	cout<<"0 0\n";
	return 0;
}