#include <bits/stdc++.h>
using namespace std;
int arr[2000001], n, m;
vector <int> numeros;
int main()
{
	int j, x;
	while (cin>>n)
	{
		memset(arr, 0, sizeof arr);
		numeros.clear();

		for (int i = 0; i < n; ++i)
		{
			cin>>x;
			numeros.push_back(x);
			++arr[x];
		}
		cin>>m;
		if ( (m&1)==0 and arr[m>>1]>1)
		{
			cout<<"Peter should buy books whose prices are "<<(m>>1)<<" and "<<(m>>1)<<".\n\n";
			continue;
		}
		sort(numeros.begin(), numeros.end());
		j = lower_bound(numeros.begin(), numeros.end(), m>>1) - numeros.begin();
		while(numeros[j]>(m>>1)) --j;
		while (j>=0)
		{
			if ( arr[ m - numeros[j] ] and (m - numeros[j])!= numeros[j] )
			{
				cout<<"Peter should buy books whose prices are "<<numeros[j]<<" and "<<m - numeros[j]<<".\n\n";
				break;				
			}	
			--j;			
		}
	}
	return 0;
}