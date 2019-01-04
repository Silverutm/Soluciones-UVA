#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef unsigned long long ll;

ll fac[23];

ll factorial( ll n )
{
	ll &r=fac[n];
	if (r) return r;
	return r=n*factorial(n-1);
}

string s;
void permutacion(ll n)
{
	if ( !s.size() ) return;

	ll k= factorial( s.size()-1 );
	cout<<s[ n/k ];
	s.erase(n/k, 1);
	permutacion( n%k );
}

int main()
{
	/*
	int contador=0;
	string ss("eklln");
	do
	{
		cout<<contador<<"  "<<ss<<endl;
		++contador;
		if (contador%24==0) cout<<endl;

	}while ( next_permutation(ss.begin(), ss.end() )  );
	//*/
	/*
	n=20;
	k = 20/6;
	cout<<s[k];
	s.erase(k, 1);
	*/
	fac[0]=fac[1]=1;
	int t;
	ll n;
	cin>>t;
	//cout<<factorial(19)<<endl;
	while (t--)
	{
		cin>>s>>n;
		sort (s.begin(), s.end() );
		//cout<<s<<endl;
		permutacion( n );
		cout<<endl;
	}
	return 0;
}