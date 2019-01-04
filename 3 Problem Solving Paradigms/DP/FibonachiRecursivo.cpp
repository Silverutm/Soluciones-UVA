#include <iostream>
using namespace std;
typedef long long ll;

ll FuncBinom(int n, int k )
{
	if (n==k or k==0 ) return 1;
	return FuncBinom(n-1, k-1) + FuncBinom(n-1, k);
}

int main()
{
	int n, k;
	cin>>n>>k;
	cout<<FuncBinom(n, k)<<endl;
	return 0;
}