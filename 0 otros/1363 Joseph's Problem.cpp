#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	long long n, k, res;
	while (scanf("%ld %ld", &n, &k)==2)
	{
		res=0;
		if (n>k)
		{
			res=(n-k)*k;
			for (int i=2; i<k; ++i)
				res += k%i;
		}
		else
			for (int i=2; i<=n; ++i)
				res += k%i;
		printf("%lld\n", res);	
	}
	return 0;
}