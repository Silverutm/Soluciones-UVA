#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef pair <char, int> ci;
typedef vector < ci > vci;
int longitud[10009];
string s;

int maximo()
{
	int j=0, mayor=longitud[0];
	for (int i=1; i<s.size();++i)
		if (longitud[i]>mayor)
		{
			mayor=longitud[i];
			j=i;
		}
	return j;
}

int main()
{
	int t, res;
	scanf("%d", &t);
	int i;
	vci respesta;
	while (t--)
	{
		cin>>s;
		s = s + s;
		longitud[0]=1;
		for (i=1; i<s.size();++i)
			if ( s[i]>=s[i-1] )
				longitud[i]=longitud[i-1]+1;
			else longitud[i]=1;
		res=maximo();
		printf("%d\n", res- longitud[res]+2);
	}
	return 0;
}