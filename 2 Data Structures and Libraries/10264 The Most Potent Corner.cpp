#include <iostream>
#include <algorithm>
using namespace std;
int arr[1<<16], suma[1<<16];

int main()
{
	int n, lim, k, mayor;
	while (cin>>n)
	{
		lim = 1<<n;
		mayor = 0;

		for (int i = 0; i < lim; ++i)		
			cin>>arr[i];

		for (int i = 0; i < lim; ++i)
		{
			suma[i] = 0;
			for (int j = 0; j < n; ++j)			
				if ( i&(1<<j) )				
					suma[i] += arr[ i-(1<<j) ];				
				else suma[i] += arr[ i+(1<<j) ];			
		}
		for (int i = 0; i < lim; ++i)
		{			
			for (int j = 0; j < n; ++j)			
				if ( i&(1<<j) )				
					mayor = max( suma[i] + suma[ i-(1<<j) ] , mayor) ;
				else mayor = max( suma[i] + suma[ i+(1<<j) ] , mayor);			
		}
		cout<<mayor<<endl;
	}
	return 0;
}