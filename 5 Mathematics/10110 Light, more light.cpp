#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double n, raiz;
	while (cin>>n and n)
	{
		raiz = sqrt(n);
		//raiz = floor(n);
		if (floor(raiz)==ceil(raiz))
			cout<<"yes\n";
		else cout<<"no\n";
	}
	return 0;
}