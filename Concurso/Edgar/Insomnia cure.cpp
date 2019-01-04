#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <vector>
#include <bitset>
#include <map>
#include <cmath>
#include <queue>
#define f first
#define s second
#define mk make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair <int, int> ii;
typedef pair<ll, ll> pll;
typedef vector <int> vi;
typedef vector <vi> vvi;
int gcd1(int a, int b)
{ return b==0 ? a:gcd1(b, a%b); }
int gcd(int a, int b)
{
	return a*b/gcd1(a,b);
}
//vi indices;
/*void cuenta(i)
{
	indices.clear();
	while (i)
	{
		if ( i%2 ) ++cuenta;
		i /=2;
	}
	if (cuenta%2) signo=1;
	else signo=-1;
}*/
int main()
{
	int x[5], d, i, c, signo, res=0;
	cin>>x[0]>>x[1]>>x[2]>>x[3]>>d;
	//res=d;
	/*for (i=0; i< (1<<4); ++i )
	{
		cuenta(i);
		r += signo*( d/g(i) );
	}*/

	res = d/x[0] + d/x[1] + d/x[2] + d/x[3];
	res += -d/gcd(x[0], x[1]) -d/gcd(x[0], x[2]) -d/gcd(x[0], x[3])
			-d/gcd(x[1], x[2]) -d/gcd(x[1], x[3])
			-d/gcd(x[2], x[3]);
	res += d/gcd(x[0], gcd(x[1], x[2]) ) +d/gcd(x[0], gcd(x[1], x[3]) )   
			+d/gcd(x[0], gcd(x[2], x[3]) ) +d/gcd(x[1], gcd(x[2], x[3]) );
	res += -d/gcd(gcd(x[0], x[1]), gcd(x[2], x[3]) );
	
	cout<<res<<endl;
	return 0;
}