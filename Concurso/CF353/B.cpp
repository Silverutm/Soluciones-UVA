#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;
int main()
{
	long long n, a, b, c, d, x1, x2, x3, x4, x5, res;
	//scanf("%lld %lld %lld %lld %lld", &n, &a, &b, &c, &d);
	//for (x1=1; x1<=n; ++x1)
	

	cin>>n>>a>>b>>c>>d;
	x1 = max(1-b+c,max( 1-a+d, 1-a-b+c+d)  );
	x2 =  min(n-b+c,min( n-a+d, n-a-b+c+d)  );
	if (x1<=0) x1=1;

	if (x2>n) x2=n;
	res=x2-x1+1;
	if (res<=0) res=0;
	res*=n;

	//x1 = n-x1+1;

	//x1 *=n;
	//if (x1<=0) x1=0;


	cout<<res<<endl;

	

	//else printf("%lld\n",x1 );
	return 0;
}