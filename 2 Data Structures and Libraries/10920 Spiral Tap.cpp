#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{	
	ll p, n, s, f, c;	
	while (cin>>s>>p, s)
	{
		n= ceil(sqrt(p)); 
		if ( not (n&1) ) ++n;		
		if ( p >= n*n -n + 1 ) //vertical derecha
		{
			c=n;
			f = p - ( n*n -n + 1 ) + 1;
		}
		else if ( p >= n*n -2*n + 2 )  //horizontal abajo
		{
			f=1;
			c = p - ( n*n -2*n + 2 ) + 1;
		}
		else if ( p >= n*n -3*n + 3 ) //vertical izquierda
		{
			c=1;
			f = n*n -2*n + 2 - p + 1;
		}
		else	//horizontal arriba 
		{
			f=n;
			c = n*n -3*n + 3 - p + 1;
		}
		f += (s-n)/2; c += (s-n)/2;		
		cout<<"Line = "<< f<<", column = "<< c <<".\n";
	}
	return 0;
}