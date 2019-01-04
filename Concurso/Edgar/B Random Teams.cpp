#include <iostream>
using namespace std;
int main()
{
	long long n,m, k, kp;
	while(cin>>n>>m)
	{
		k=n/m;
		kp=n-m+1;
		cout<<(k+1)*k/2 *(n%m) + k*(k-1)/2*(m-n%m)<<" "<<kp*(kp-1)/2<<endl;
	}
}