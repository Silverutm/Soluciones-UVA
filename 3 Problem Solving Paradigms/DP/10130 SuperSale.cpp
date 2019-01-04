#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define tam 1009
using namespace std;
int precio[tam], peso[tam], respuesta[tam][35], n;

int mayorvalor(int obj, int w)
{
	if (w<0) return -100000000;
	if (obj==n) return 0;
	int &res = respuesta[obj][w];
	if (res!=-1) return res;
	res = max( mayorvalor(obj+1, w - peso[obj] )+precio[obj],
				mayorvalor(obj+1, w) );
	//cout<<obj<<" "<<w<<" "<<res<<endl;
	return res;
}

int main()
{
	int res, t, p, g, w, i;
	scanf("%d", &t);
	while (t--)
	{
		memset(respuesta, -1, sizeof respuesta);
		scanf("%d", &n);
		for (i=0; i<n; ++i)
			scanf("%d %d", &precio[i], &peso[i]);

		res=0;
		scanf("%d", &g);
		for (i=0; i<g; ++i)
		{
			scanf("%d", &w);
			res += mayorvalor(0,w);
		}
		printf("%d\n", res);
	}
	return 0;
}