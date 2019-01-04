#include <bits/stdc++.h>
using namespace std;
int matriz[105][105], tabla[105][105], n, res, r, c;
int f(int i, int j)
{
	if (i>=r or j>=c) return 0;
	if (tabla[i][j]!= -1) return tabla[i][j];
	return tabla[i][j]= matriz[i][j] + max(	f (i+1, j),
								f (i, j+1)	);
}
int main()
{
	cin>>n;
	char cha;
	for (int caso = 1; caso <= n; ++caso)
	{
		cin>>r>>c;
		memset (tabla, -1, sizeof tabla);
		for (int i = 0; i < r; ++i)		
			for (int j = 0; j < c; ++j)
			{
				if ( (i==0 and j==0 ) or (i==r-1 and j ==c-1) )
				{
					cin>>cha;
					matriz[i][j] = 0;
				}
				else cin>>matriz[i][j];
			}
		res= f(0,0);
		cout<<"Game Board #"<<caso<<": "<<res<<"\n";
	}
	return 0;
}