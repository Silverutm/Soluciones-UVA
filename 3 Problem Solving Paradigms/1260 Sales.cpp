#include <iostream>
using namespace std;
int arreglo[1009];
int main()
{
	int t, i, j, c, n;
	cin>>t;
	while (t--)
	{
		cin>>n;
		for (i=0; i<n; ++i)
			cin>>arreglo[i];
		c=0;
		for (i=0; i<n; ++i)
			for (j=0; j<i; ++j)
				if (arreglo[j]<=arreglo[i])
					++c;
		cout<<c<<endl;
	}
	return 0;
}