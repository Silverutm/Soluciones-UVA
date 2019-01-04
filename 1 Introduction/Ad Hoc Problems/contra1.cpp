#include <iostream>
using namespace std;
#define SZ 20
int A[SZ], B[SZ];

void merge(int a, int b)
{
	int li=(b+a)/2, j, k, po; 
	if (a!=b-1) merge(a, li), merge( li, b);
	for (po=j=a, k=li; j<li && k<b; ++po)
	{
		if (A[j]< A[k]) B[po]=A[j], ++j;
		else B[po]=A[k], ++k;  
	}
	if (j==li)
		for (; po<b; B[po]=A[k], ++po, ++k);
	else 
		for (; j<li; B[po]=A[j], ++po, ++j );
	for (j=a-1; ++j<b; A[j]= B[j]);
}

int main()
{
	int i, j;
	cin>>j;
	for (i=-1; ++i<j; cin>>A[i]);
	merge(0, j);
	for (i=-1; ++i<j; cout<<A[i]<<" ");
	return 0;
}
