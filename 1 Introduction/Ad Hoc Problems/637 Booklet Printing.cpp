#include <iostream>
#include <cstring>
#define f first
#define s second
using namespace std;
pair <int, int> impar[30], par[30];
int m;
void revisa(int a)
{
	if (a) cout<<a;
	else cout<<"Blank";
	return;
}

int valida(int a)
{
	if (a>m) return 0;
	return a; 
}

int main()
{
	int n, k;
	while (cin>>m , m)
	{
		memset(impar, 0, sizeof impar);
		memset(par, 0, sizeof par);
		n=m/4;
		if (m%4) ++n;
		for (k=1; k<=n; ++k)
		{
			impar[k].f = valida( 4*n-2*(k-1));
			impar[k].s =valida( 2*k-1);
			par[k].f = valida(2*k);
			par[k].s = valida(4*n-(2*k-1));
		}
		cout<<"Printing order for "<<m<<" pages:\n";
		for (k=1; k<=n; ++k)
		{
			if (impar[k].f or impar[k].s)
			{
				cout<<"Sheet "<<k<<", front: ";
				revisa(impar[k].f);
				cout<<", ";
				revisa(impar[k].s);
				cout<<"\n";
			}
			if (par[k].f or par[k].s)
			{
				cout<<"Sheet "<<k<<", back : ";
				revisa(par[k].f);
				cout<<", ";
				revisa(par[k].s);
				cout<<"\n";
			}
		}
	}
	return 0;
}