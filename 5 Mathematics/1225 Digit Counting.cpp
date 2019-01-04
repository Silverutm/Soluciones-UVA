#include <iostream>
using namespace std;
#define tam 60003
int res[10][tam];

void f(int n)
{
	int i=n;
	while (n)
	{
		++res[n%10][ i ];
		n /= 10;
	}
}

int main()
{
	int t, a;
	//res[0][0]=1;
	for (int i = 1; i < tam; ++i)
	{
		f(i);
		for (int j = 0; j < 10; ++j)
		{
			res[j][i] += res[j][i-1];
		}
	}
	cin>>t;
	while (t--)
	{
		cin>>a;
		cout<<res[0][a];
		for (int i = 1; i < 10; ++i)
		{
			cout<<" "<<res[i][a];
		}
		cout<<"\n";
	}
	return 0;
}