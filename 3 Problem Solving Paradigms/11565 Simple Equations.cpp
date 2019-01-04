#include <iostream>
using namespace std;
int main()
{
	int a, b, c, x, y, z, t;
	bool p;
	cin>>t;
	while (t--)
	{
		cin>>a>>b>>c;
		p=true;
		for (x=-100; x<=100 and p; ++x)
			for (y=-100; y<=100 and p; ++y)
				for (z=-100; z<=100 and p; ++z)				
					if ( (x+y+z==a) and (x*y*z==b) and (x*x+y*y+z*z==c)  )
					{
						if (x==y or x==z or y==z) continue;
						p=false;
						cout<<x<<" "<<y<<" "<<z<<endl;
					}
		if ( p)
			cout<<"No solution.\n";
	}
	return 0;
}