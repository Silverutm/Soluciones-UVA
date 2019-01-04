#include <bits/stdc++.h>
using namespace std;
#define tam 100009
int vizq[tam], vder[tam];
int main()
{
	int s, b, s1, iz, der, l , r;
	while (cin>>s>>b, s)
	{
		s1= s+1;
		for (int i = 1; i <= s1; ++i)
			vizq[i]=i-1;
		for (int i = 0; i <= s; ++i)
			vder[i]=i+1;

		while (b--)
		{
			cin>>l>>r;
			iz = vizq[l]; der = vder[r];
			vizq[der] = iz; vder[iz]=der;

			if (not iz) cout<<"*";
			else cout<<iz;
			cout<<" ";

			if ( der == s1 ) cout<<"*";
			else cout<<der;
			cout<<"\n";
		}
		cout<<"-\n";
	}
	return 0;
}