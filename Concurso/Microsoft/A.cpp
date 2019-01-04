#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector <int > v;
	int a, h, c=0, i, j;
	while (cin>>a) v.push_back(a);
	for (i=0; i<v.size(); ++i)
		for (j=i+1; j<v.size(); ++j)
		{
			if (v[i]>v[j])
			{
				h=v[i];
				v[i]=v[j];
				v[j]=h;
				++c;
			}
		}

	printf("%d\n",c );
	for (i=0; i<v.size(); ++i)
	{
		if (i) printf(" ");
		printf("%d", v[i]);
	}
	printf("\n" );
	return 0;
}