#include <iostream>
using namespace std;
#define tam 10000
int diagonal[tam];
int main()
{
	diagonal[1] = 1;
	for (int i = 2; i < tam; ++i)
		diagonal[i] = diagonal[i-1] + i - 1;

	/*for (int i = 0; i < 10; ++i)
	{
		cout<<diagonal[i]<<" ";
	}
	cout<<"\n";*/

	int k, i, n, lugar, f, c;
	while (cin>>k)
	{
		i = lower_bound( diagonal, diagonal+tam, k ) - diagonal ;
		if (diagonal[i]>k) --i;
		n = diagonal[i];

		lugar = k - n;
		/*cout<<i<<"   i\n";
		cout<<lugar<<"   lugar\n";*/
		if (i&1)
		{
			f = i - lugar;
			c = 1 + lugar;
		}
		else
		{
			f = 1 + lugar;
			c = i - lugar;
		}

		cout<<"TERM "<<k<<" IS "<<f<<"/"<<c<<"\n";
	}
	return 0;
}