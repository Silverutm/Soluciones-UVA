#include <bits/stdc++.h>
#define s second
#define f first
#define mk make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;

double x[5], y[5], p, negro, posible;

double d( int a, int b )
{
	return hypot( x[a] - x[b], y[a] - y[b] );
}

double d2( int a, int b )
{
	return ( x[a] - x[b])*( x[a] - x[b]) + ( y[a] - y[b])*( y[a] - y[b]);
}

int main()
{
	x[1]=y[1]=50.0;
	x[2] = 50.0; y[2] = 100.0;
	int t;
	cin>>t;
	for (int caso = 1; caso <= t; ++caso)
	{
		cin>>p>>x[3]>>y[3];


		cout<<"Case #"<<caso<<": ";
		negro = p * 3.6;
		posible = acos(  (  d2(1, 2) + d2(1,3) -d2(2,3) ) / ( 2*d(1,2)*d(1,3) )   )*180/(2 * acos(0.0) );
		if (x[3]==50) posible = 180.0;
		else if ( x[3]<50 ) posible = 360.0 - posible;
		if ( (fabs(posible - negro) <=1e-6 or negro >= posible) and d2(1, 3)<=2500    )
			cout<< "black\n";
		else cout<< "white\n";
	}
	
		

	return 0;
}

//arccos((P122 + P132 - P232) / (2 * P12 * P13))