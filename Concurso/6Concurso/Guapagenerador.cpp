#include <iostream>
#include <cstdlib>
#include <ctime>  
#include <set>
using namespace std;

int azar(int a, int b)
{
	return rand()%b + a;
}

distancia(int x1, int y1, int x2, int y2)
{
	return abs(x1-x2) +abs(y1-y2);
}

int main()
{
	srand (time(NULL));
	int t=100, x, y,k, n, x1, y1, i, d, g;
	cout<<t<<endl;
	set <int> miset;
	while (t--)
	{
		miset.clear();
		//casa de Gio
		x=azar(-997, 1999);
		y=azar(-997, 1999);
		cout<<x<<" "<<y<<endl;
		
		//numero de amigos
		n=azar(3, 990);
		cout<<n<<endl;

		for (i=0; i<n; ++i)
		{
			do
			{
				x1=azar(-997, 1999);
				y1=azar(-997, 1999);
				d=distancia(x1,y1, x, y);
			} while ( miset.find(d)!=miset.end() );
			miset.insert(d);
			g=azar(0, 2);
			cout<<x1<<" "<<y1<<" "<<g<<endl;			
		}
		k=azar(1, n) ;
		cout<<k<<endl;
	}	
	return 0;
}