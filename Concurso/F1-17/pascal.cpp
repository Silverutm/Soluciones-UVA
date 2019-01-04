#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

ll TablaBinom[100][100];
void LLenar( )
{
	int i, j;
	for (i=0; i<67; ++i)
		TablaBinom[i][0]=TablaBinom[i][i]=1;
	
	for (i=2; i<67; ++i)
		for (j=1; j<i; ++j)
		TablaBinom[i][j] = TablaBinom[i-1][j]
				+ TablaBinom[i-1][j-1];
}

int main()
{
	int n, k;
	LLenar();
	for (n=2; n<=65; ++n, cout<<endl)
	for (int k = 0; k <= n; ++k)
	{
		cout<<TablaBinom[n][k]%4 <<"  " ;
	}
	return 0;
}