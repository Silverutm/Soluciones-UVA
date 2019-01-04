#include <bits/stdc++.h>
using namespace std;
#define tam 25
int m, n;
char tierra;
string tablero[tam];
//int res[tam][tam];
vector <int> res;

int buscar(int y,int x)
{
	if (y<0 or y>=m ) return 0;
	if (x<0) x= n-1;
	else if (x==n) x=0;

	if (tablero[y][x]!=tierra) return 0;

	tablero[y][x] = tierra+1;

	return 1 + buscar(y-1, x) + buscar(y+1, x) + 
			   buscar(y, x+1) + buscar(y,x - 1);
}

int main()
{
	int y, x;
	while (cin>>m>>n)
	{		
		res.clear();

		for (int i = 0; i < m; ++i)
			cin>>tablero[i];

		cin>>y>>x;
		tierra = tablero[y][x];
		int z = buscar(y, x);
		res.push_back( z );

		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				if (tablero[i][j]==tierra)
					res.push_back( buscar(i, j) );					

		sort(res.begin(), res.end());
		if (res.size()==1) cout<<"0\n";
		else 
		{
			if (res[res.size()-1]==z ) cout<<res[res.size()-2]<<"\n";
			else cout<<res[res.size()-1]<<"\n";
		}
	}
	return 0;
}