#include <iostream>
#include <algorithm>
using namespace std;
int matriz[10][10], r[8];
int main()
{
	int t, i, j ,res, parcial, n;
	cin>>t;
	while (t--)
	{
		cin>>n;
		for (i=0; i<n; ++i)
			for (j=0; j<n; ++j)
				cin>>matriz[i][j];
		for (i=0; i<n; ++i)
			r[i]=i;
		res=800000;
		do
		{
			parcial=0;
			for (i=0; i<n; ++i)
				parcial+=matriz[ i ][ r[i] ];
			res=min(res, parcial);
		}while(next_permutation(r, r+n));
		cout<<res<<endl;
	}
	return 0;
}