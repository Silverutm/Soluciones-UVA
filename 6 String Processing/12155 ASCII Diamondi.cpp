#include <iostream>
using namespace std;
int main()
{
	int n, x, y, y2, x2, v,i=0, x1, y1, xx, yy;
	while (cin>>n and n)
	{
		cin>>y1>>x1>>y2>>x2;
		cout<<"Case "<<++i<<":\n";

		for ( yy = y1; yy <= y2; ++yy)
		{
			for ( xx = x1 ; xx <= x2; ++xx)
			{
				x = xx; y = yy;

				y %= ( 2*n-1 );  x %= ( 2*n-1 );

				if ( y >= n ) y = 2*n - 2 - y;
				if ( x >= n ) x = 2*n - 2 - x;

				v = 2*n - 1 - ( x + y );  

				if ( v>n ) cout<<".";
				else
				{
					--v;
					v %= 26;
					cout<<( char ) ( v + 'a' );
				}
			}
			cout<<endl;
		}

	}
	return 0;
}