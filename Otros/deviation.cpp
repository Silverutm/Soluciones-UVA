#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	double n;
	//for (i=1; i<=temp; i+=2)
	//	raiz[i*i]=i;
	while(cin>>n, n)
	{
		printf("%lf\n", sqrt( ( ((4*n*(n+1)*(2*n+1))/6)-(2*n*(n+1))+n-n*n*n) /(n-1))  );
	}
	return 0;
}