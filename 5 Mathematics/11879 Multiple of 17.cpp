#include <iostream>
using namespace std;
int main()
{
	int arr[105], res; arr[0]=1;
	for (int i = 1; i < 103; ++i)
		arr[i] = arr[i-1] * 10 % 17;
	string x;
	while (cin>>x and x!="0")
	{
		res=0;
		for (int i = 0; i < x.size(); ++i)
			res = (res + (x[i]-'0')*arr[ x.size()-1-i ] )% 17;
		cout<< !res <<endl;
	}
	return 0;
}