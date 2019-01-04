#include <iostream>
using namespace std;
int main()
{
	int n, k, a, s;
	while (cin>>n>>k and n)
	{
		s=0;
		while (n--)
		{
			cin>>a;
			s += a;
		}
		cout<<k/s<<"\n";
	}
	return 0;
}