#include <iostream>
#include <algorithm>
using namespace std;
#define dinero 1000009
int arreglo[dinero];
int main()
{
	int n, d,i, cantidad;
	cin>>d>>n;
	for (i=0; i<n; ++i)
		cin>>arreglo[i];
	sort(arreglo, arreglo+n);
	i=0;
	cantidad=0;
	while(  d-arreglo[i]>=0 )
	{
		cantidad++;
		d-=arreglo[i];
		++i;
	}
	cout<<cantidad<<endl;
	return 0;
}