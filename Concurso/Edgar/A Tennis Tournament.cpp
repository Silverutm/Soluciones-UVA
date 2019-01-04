#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n, b, p, l;
	while (cin>>n>>b>>p)
	{
		cout<<(exp2( (int)ceil(log2(n) ) )-1)*(2*b+1)-( exp2( (int)ceil(log2(n) ) )-n )*(2*b+1)<<" "<<n*p<<endl;
	}
	return 0;
}