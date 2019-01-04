#include <cstdio>
#include <cstring>
#define tras 50
using namespace std;
int matriz[20000][20000], d;

int calcular(int cx, int cy)
{
	int i, j,tot=0;
	for (i=-d; i<=d ;++i)
		for (j=-d; j<=d ;++j)
			tot+=matriz[i+cx][j+cy];
	return tot;
}

int fil(int cx, int cy)
{
	int tot=0;
	for (int i=-d; i<=d; ++i)
		tot+=matriz[cx+i][cy];
	return tot;
}

int min(int a, int b)
{
	return a < b ? a:b;
}

int main()
{
	int t, x, y, c, xt, yt, i, j, matados, anterior, rx=0, ry=0, n;
	scanf("%d", &t);
	while (t--)
	{
		//memset(matriz, 0, sizeof matriz);
		//if ()
		for (j=d; j<=xt;  ++j)
			for (i=d; i<=yt;  ++i)
				matriz[j][i]=0;

		scanf("%d %d", &d, &n);
		rx=ry=d;
		if (d<0) d=-d;
		while (n--)
		{
			scanf("%d %d %d", &x, &y, &c);
			matriz[x+d][y+d]=c;
			xt=xt+x-min(xt,x);
			yt=yt+y-min(yt,y);
		}
		xt+=d; yt +=d;

		matados=calcular(d, d);

		for (j=d; j<=xt;  ++j)
			for (i=d; i<=yt;  ++i)
			{
				if (i==d) anterior=calcular(j, i);
				else anterior=anterior-fil(j,i-d-1)+ fil(j,i+d);
				if (anterior>matados)
				{
					matados=anterior;
					rx=j; ry=i;
				}
			}
		printf("%d %d %d\n",rx-d, ry-d, matados );
	}
	return 0;
}