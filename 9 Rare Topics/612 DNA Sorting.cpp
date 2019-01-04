#include <iostream>
#include <string>
using namespace std;
#define M 1006
int c[2][M], d[2][M], i;
string A[M], B[M], P[M];

int merge(int a, int b)
{
	int li=(b+a)/2, j, k, po; 
	if (a!=b-1) merge(a, li), merge( li, b);
	for (po=j=a, k=li; j<li && k<b; ++po)
	{
		if (A[i][j]<= A[i][k]) B[i][po]=A[i][j], ++j;
		else B[i][po]=A[i][k], ++k, c[0][i]+=li-j; 
	}
	if (j==li)
		for (; po<b; B[i][po]=A[i][k], ++po, ++k);
	else 
		for (; j<li; B[i][po]=A[i][j], ++po, ++j );
	for (j=a-1; ++j<b; A[i][j]= B[i][j]);
	return 0;
}

void mergep(int a, int b)
{
	int li=(b+a)/2, j, k, po; 
	if (a!=b-1) mergep(a, li), mergep( li, b);
	for (po=j=a, k=li; j<li && k<b; ++po)
	{
		if (c[0][j]<= c[0][k]) d[0][po]=c[0][j], d[1][po]=c[1][j], ++j;
		else d[0][po]=c[0][k], d[1][po]=c[1][k] , ++k;
	}
	if (j==li)
		for (; po<b; d[0][po]=c[0][k],  d[1][po]=c[1][k],  ++po, ++k);
	else 
		for (; j<li; d[0][po]=c[0][j], d[1][po]=c[1][j] , ++po, ++j );
	for (j=a-1; ++j<b; c[0][j]= d[0][j],  c[1][j]= d[1][j]);
}




int main()
{
	int j, t, m;
	cin>>t;
	while(t--)
	{
		cin>>j>>m;
		for (i=-1; ++i<m; cin>>A[i], P[i]=A[i], merge(c[0][ c[1][i]=i ]=0, j) );
		mergep(0, m); 
		for (i=-1; ++i<m; cout<<P[ c[1][i] ]<<endl );
		if (t) cout<<endl;
	}
return 0;
}