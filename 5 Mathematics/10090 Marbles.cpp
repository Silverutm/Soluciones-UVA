#include <iostream>
using namespace std;
int x, y, d;
void ecuaciondiofantica (int a, int b)
{
	if (b==0)
	{
		x=1;
		y=0;
		d=a;
		return;
	}

	ecuaciondiofantica (b,a%b);
	int x1=y;
	int y1=x-(a/b)*y;
	x=x1;
	y=y1;
}

int main()
{
	int a, b;
	while (cin>>a>>b)
	{
		ecuaciondiofantica(a,b);
		cout<<x<<" "<<y<<" "<<d<<"\n";	
	}
	return 0;
}