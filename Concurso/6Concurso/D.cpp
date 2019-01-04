#include <iostream>
using namespace std;
int main()
{
	int t, a, b;
	cin>>t;
	while (t--)
	{
		cin>>a>>b;
		if (a<=3 and b>=7)
			cout<<1<<endl;
		else cout<<0<<endl;
	}
	return 0;
}