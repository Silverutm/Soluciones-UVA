#include <iostream>
using namespace std;
int c, r;
void p()
{
	if (c) cout<<" ";
	c=1;
	cout<<r;
}
int main()
{
	int n, m, x;
	cin>>n>>m;
	for (x=1; x<=n; ++x)
	{		
		r=2*n+2*x-1;
		if (r<=m) p();

		r=2*x-1;
		if (r<=m) p();

		r=2*n+2*x;
		if (r<=m) p();

		r=2*x;
		if (r<=m) p();
	}
	cout<<endl;
}