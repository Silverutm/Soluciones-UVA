#include <iostream>
using namespace std;
int main()
{
	long long n, a, b, k;
	bool ba;
	while (cin>>n and n)
	{
		a = b = 0;
		k=1;
		ba = true;

		while (k<=n)
		{
			if ( k&n)
			{
				if (ba)
					a +=k;
				else b +=k;
				ba = not ba;
			}
			k <<=1;
		}
		cout<< a<<" "<<b<<"\n";
	}
	return 0;
}