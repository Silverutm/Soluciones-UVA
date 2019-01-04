#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;
int main()
{
	int n, p, c;
	vector <int > v;
	set <int > s;
	for (int a=0; a<=20; ++a)
	{
		s.insert(a);
		s.insert(a*2);
		s.insert(a*3);
	}
	s.insert(50);
	for (auto s1:s)
	{
		v.push_back(s1);
	}
	//v.push_back(50);
	while (cin>>n)
	{
		if (n<=0) break;
		p=c=0;
		for (auto i:v)
			for (auto j:v)
				for (auto k:v)
					if (i+j+k==n)
					{
						++p;
						if (i<=j and j<=k)
							++c;
					}
		if (c)
		{
			printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n",n,c );
			printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", n, p);				
		}
		else
			printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", n);
		printf("**********************************************************************\n");
	}
	printf("END OF OUTPUT\n");
	return 0;
}