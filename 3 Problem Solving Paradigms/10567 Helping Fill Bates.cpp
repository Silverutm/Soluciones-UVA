#include <bits/stdc++.h>
using namespace std;
string A, B;
int i;

void buscar(char e)
{
	while ( i<A.size() and A[i]!=e) ++i;
}

int main()
{
	bool primera;
	int ini, k;
	cin>>A;
	cin>>k;
	while (k--)
	{
		primera = true;
		cin>>B;	
		i=-1;
		for (auto e:B)
		{
			++i;
			buscar(e);
			if ( i==A.size() ) break;

			if (primera)
			{
				ini = i;
				primera = false;
			}
		}
		if (i!=A.size())
			cout<<"Matched "<<ini<<" "<<i<<"\n";
		else cout<<"Not matched\n";
	}
	return 0;
}