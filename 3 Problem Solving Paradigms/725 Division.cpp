#include <iostream>
using namespace std;
int main()
{
	int a, b, n, arr[11], i, k, c=0, sol;
	bool posible;
	while (cin>>n and n)
	{
		if (c) cout<<endl;
		++c;
		sol=0;
		for (b=1234; b<=98765; ++b)
		{
			a=n*b;
			posible=true;			
			for (i=0; i<=9; ++i) arr[i]=0;
			if (a>98765) break;
			k=a;
			for (i=1; i<=5 and posible; ++i)
			{
				
				if ( ++arr[ k%10 ] -1 ) posible=false;
				k /=10;
			}
			k=b;
			for (i=1; i<=5 and posible; ++i)
			{
				if ( ++arr[ k%10 ] -1 ) posible=false;
				k /=10;
			}
			if (posible)
			{
				if (a<10000) cout<<"0";
				cout<<a<<" / ";
				if (b<10000) cout<<"0";
				cout<<b<<" = "<<n<<endl;
				sol=1;
			}			
		}
		if (sol==0) cout<<"There are no solutions for "<<n<<".\n";
	}
	return 0;
}