#include <iostream>
using namespace std;
int main()
{
	int letras = 'z' -'a' + 1;
	int n, r, total, caso=0;
	while (cin>>n>>r and n)
	{
		total = (n-1) / r;
		cout<<"Case "<<++caso<<": ";
		if (total > letras)
			cout<<"impossible\n";
		else cout<<total<<endl;
	}
	return 0;
}