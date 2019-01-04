#include <iostream>
#include <bitset>
#include <vector>
#include <cstring>
using namespace std;

bool RP[25][205];
vector < vector<int> > tabla;
int d, k;

void resolver()
{
	int i, j;
	for ( auto p: tabla[0] )
		if (p<=d) RP[0][p]=true;

	for (i=0; i<k-1; i++)
	{
		for ( j=0; j<=d; ++j )
			if ( RP[i][j] )
			{
				for (auto p: tabla[i+1] )
				{
					auto p2 = p + j;
					if (p2<=d) RP[i+1][p2]=true;
				}
			} 
	}
}




void imprime()
{
	for (auto v:tabla)
	{
		for (auto c:v)
			cout<<c<<" ";
		cout<<endl;
	}

	for (int i=0; i<k; ++i, cout<<endl)
		for (int j=0; j<=d; ++j)
			cout<<RP[i][j];
}


int main()
{
	int t, a,n, i;
	cin>>t;
	while (t--)
	{		
		cin>>d>>k;
		
		tabla.clear();
		tabla.resize(k+1);
		memset(RP, false, sizeof RP);
		//imprime();		
		for (i=0; i<k; ++i)
		{
			cin>>n;
			while (n--)
			{
				cin>>a;
				tabla[i].push_back(a);
			}
		}
		resolver();
		//imprime();
		for (i=d; i>=0; --i)
			if ( RP[k-1][i] ) break;
		if (i<0) cout<<"no solution\n";
		else cout<<i<<endl;
	}
	return 0;
}