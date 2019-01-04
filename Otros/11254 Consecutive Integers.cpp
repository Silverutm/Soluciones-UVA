#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
int main()
{
	ll r, n, k;
	while (cin>>r and r!=-1)
	{
		n=sqrt(8*r+1)-1;
		n >>=1;
		++n;
		while (--n)
		{
			k= 2*r-n*(n+1) ;
			if ( k%(2*n) ) continue;
			k /=2*n;
			cout<<r<<" = "<<1+k<<" + ... + "<<n+k<<endl;
			break;
		}
	}
	return 0;	
}