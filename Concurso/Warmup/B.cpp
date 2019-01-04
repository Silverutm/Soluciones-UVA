#include <bits/stdc++.h>
using namespace std;
int arreglo[5000];
int main()
{
	int p;
	for (int i = 1; i < 10000; ++i)
	{
		p=0;
		for (int j=1; j<=i; ++j)
			if (i%j==0) p+=j;
		if (p<=1000)
		arreglo[p]=i;
	}
	for (int i = 0; i < 1001; ++i)
	{
		cout<<arreglo[i]<<",";
	}
	return 0;
}