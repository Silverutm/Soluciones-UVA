#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

//Funcion recursiva
ll FuncFibo(ll n )
{
	if (n<=1) return n;
	return FuncFibo(n-1) +FuncFibo(n-2);
}




ll TablaFibo[100];
ll DPFibo( ll n )
{
	if (TablaFibo[n]!=-1) return TablaFibo[n];
	
	if (n<=1) return TablaFibo[n] = n;
	return TablaFibo[n] = DPFibo(n-1) +DPFibo(n-2);
}


int main()
{
	ll n;
	cin>>n;
	//cout<<FuncFibo(n)<<endl;

	memset(TablaFibo, -1, sizeof TablaFibo);
	cout<<DPFibo(n)<<endl;
	return 0;
}