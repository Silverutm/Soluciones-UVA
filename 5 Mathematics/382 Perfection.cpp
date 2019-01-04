#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n;
void veredicto()
{
	int res = -n, raiz = sqrt(n)+1;
	for (int i = 1; i < raiz; ++i)
		if ( n%i == 0 )
		{
			res += i;
			if ( i != (n/i) )
				res +=n/i;
		}
	if (res == n) cout<<"PERFECT\n";
	else if ( res<n ) cout<<"DEFICIENT\n";
	else cout<<"ABUNDANT\n";
}
int main()
{	
	printf("PERFECTION OUTPUT\n");
	while(cin>>n and n)
	{
		printf("%5d  ", n);
		veredicto();
	}
	printf("END OF OUTPUT\n");
	return 0;
}