#include <iostream>
using namespace std;
int arreglo[109];
int main()
{
	int t, n, dinero, cant, i;
	cin>>t;
	while (t--)
	{
		cin>>n;
		for (i=0; i<n;++i )
			cin>>arreglo[i];
		dinero=0;
		cant=1;
		for (i=0; i<n-1;++i )
			if (arreglo[i]+dinero < arreglo[i+1])
			{	
				++cant;
				dinero+=arreglo[i];
			}
		cout<<cant<<endl;
	}
	return 0;
}