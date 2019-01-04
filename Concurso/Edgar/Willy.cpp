#include <iostream>
using namespace std;
int residuo[100009];
int main()
{
	residuo[1]=1;
	for (int i=2; i<=100000;++i)
		residuo[i]=residuo[i-1]*10%7;
	string sols[]={"0","20","110","200","80","170","50"};
	int n;
	while (cin>>n)
	{
		if (n<=2) cout<<"-1\n";
		else if (n==3) cout<<"210\n";
		else
		{
			cout<<"1";
			for (int i=1; i<n-sols[residuo[n]].size(); ++i)
				cout<<"0";
			cout<<sols[residuo[n]]<<endl;
		}
	}
	return 0;
}