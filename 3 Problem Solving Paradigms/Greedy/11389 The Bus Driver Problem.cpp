#include <iostream>
#include <algorithm>
using namespace std;
bool f(int a, int b)
{ return a>b ; }

int main()
{	
	int n, r, d, i, mana[1003], tarde[1003], suma;
	while (cin>>n>>d>>r and (n or d or r) )
	{
		for (i=0; i<n; ++i)
			cin>>mana[i];
		for (i=0; i<n; ++i)
			cin>>tarde[i];
		sort(mana, mana+n);
		sort(tarde, tarde+n, f);
		suma=0;
		for (i=0; i<n; ++i)
			if ( mana[i]+ tarde[i]> d )
				suma += (-d+mana[i]+ tarde[i])*r;
		cout <<suma<<endl;
	}
	return 0;
}