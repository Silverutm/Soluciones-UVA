#include <iostream>
using namespace std;
#define tam 500005
int res[tam];

int main()
{
	res[1] = 1; res[2] = 2;
	int sig = 4, j, n;
	for (int i = 3; i < tam; )
	{
		j = 2;
		while ( i<tam and j<=sig )
		{
			res[i] = j;
			++i;
			j += 2;
		}
		sig <<= 1;
	}

	while (cin>>n and n)
		cout<<res[n]<<"\n";
	return 0;
}