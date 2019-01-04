#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define tam 50006
int entrada[tam], izq[tam], der[tam];
int main()
{
	int n, altura, res;
	while ( scanf("%d", &n)==1 )
	{
		for (int i = 0; i < n; ++i)
			scanf("%d", &entrada[i]);

		altura = 1;
		for (int i = 0; i < n; ++i)
		{
			izq[i] = min( entrada[i], altura );
			altura= izq[i]+1;
		}
		altura = 1;
		for (int i = n-1; i >= 0; --i)
		{
			der[i] = min( entrada[i], altura );
			altura= der[i]+1;
		}
		res = 1;
		for (int i = 0; i < n; ++i)
			res = max(res, min( izq[i], der[i] ));
		printf("%d\n", res);
	}
	return 0;
}