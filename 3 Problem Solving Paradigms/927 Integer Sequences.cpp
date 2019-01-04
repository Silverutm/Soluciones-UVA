#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
int c[30];
ll potencia[30];

ll elevar(int i, ll n)
{
	ll &p=potencia[i];
	if (p!=-1) return p;
	else return p=n*elevar(i-1, n);
}

int main()
{
	ll k, d, r, n, an;
	int i, j, t;
	cin>>t;
	while (t--)
	{
		cin>>i;
		memset(potencia, -1, sizeof potencia);
		for (j=0; j<=i; ++j)
			cin>>c[j];
		cin>>d>>k;
		for (n=1, r=n*d; r<k ; )
		{
			++n;
			r +=n*d;
		}
		an=0;
		potencia[0]=1;
		for (j=0; j<=i; ++j)
			an+=c[j]*elevar(j, n);
		cout<<an<<endl;

	}
	return 0;
}