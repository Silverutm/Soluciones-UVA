#include <bits/stdc++.h>
using namespace std;

long long arr[5];
int n, d;

long long mini()
{
	d=0;	
	for (int i = 1; i < 5; ++i)
		if (arr[i]<arr[d]) d=i;
	return arr[d];
}

int main()
{	
	//auto p = arr;
	scanf ("%d", &n);
	for (int caso = 1; caso <= n; ++caso)	
	{
		for (int i = 0; i < 5; ++i)
			scanf ("%lld", &arr[i]);

		while ( mini() <0 )
		{
			//d = p - arr;
			arr[(d+1)%5] += arr[d];
			arr[(d+4)%5] += arr[d];
			arr[d] = -arr[d];
		}
		printf("Pentagon #%d:\n", caso);
		for (int i = 0; i < 4; ++i)
			printf ("%lld ", arr[i]);
		printf ("%lld\n", arr[4]);		
	}
	return 0;
}