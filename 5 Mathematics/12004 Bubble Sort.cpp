#include <iostream>
using namespace std;
#define tam 100005
long long res[tam];
int main()
{
	int t;
	long long a;
	for (int i = 1; i < tam; ++i)
		res[i] = res[i-1] + i-1;
	
	cin>>t;
	for (int caso = 1; caso <= t; ++caso)
	{
		cout<<"Case "<<caso<<": ";
		cin>>a;
		a = res[a];
		if (a&1)
			cout<<a<<"/2\n";
		else cout<<(a>>1)<<"\n";
	}
	return 0;
}