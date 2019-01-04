#include <iostream>
using namespace std;
int t, arr[1010], maximos[1010], i, j, n;

int mayor()
{
	int may=maximos[0];
	for (i=1; i<n; ++i)
		if (maximos[i]>may)
			may=maximos[i];
	return may;
}

int main()
{
	cin>>t;
	int ant, valido;
	while (t--)
	{
		cin>>n;
		ant=0;
		valido=0;
		for (i=0; i<n; ++i)
			cin>>arr[i];
		for (i=0; i<n; ++i)
			if (ant<arr[i])
			{
				++valido;
				ant +=arr[i];
			}	

			/*maximos[i]=2;
		for (i=1; i<n; ++i)
			for (j=i+1; j<n; ++j )
				if ( arr[j]%arr[i]==0 )
					++maximos[i];*/

		cout<<valido<<endl;
	}
	return 0;
}