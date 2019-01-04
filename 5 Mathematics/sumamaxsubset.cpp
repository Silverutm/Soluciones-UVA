#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
	vector <int> numeros;
	long long suma=0;
	long long mayor=0;
	int a;
	while(cin>>a)
	{

		numeros.push_back(a);
	}
	sort(numeros.begin(),numeros.end());
	int o=0;
	for(int i=numeros.size()-1; i>=0; i--)
	{
		o++;
		suma+=(numeros[i]*pow(2,numeros.size()-o));
	}


	cout<<suma;

	return 0;
}