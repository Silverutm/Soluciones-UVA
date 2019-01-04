#include <iostream>
using namespace std;
int main()
{
	int a, b, r,n,m;
	while (cin>>n>>m and (n|| m) )
	{
		a = n<m ? n:m;
		b = n>m ? n:m;
		if (m==0 or n==0) r=0;
		else if (a==1) r=b;
		else if (a==2 and b>=4)
		{
			int w=(b-(b/4)*4);				
			if (w==0) r=0;
			else if (w==1) r=2;
			else r=4;
			r+=(b/4)*4;

		}					
		else if (a==2)
			r=(b-(b/4)*4)==1 ? 2:4;
		else if (a%2==0)
			r=(a/2)*b;
		else if (b%2==0)
			r=(b/2)*a;
		else r=((b+1)/2)*a-a/2;
		cout<<r<<" knights may be placed on a "<<n<<" row "
		<<m<<" column board."<<endl;
	}
	return 0;
}