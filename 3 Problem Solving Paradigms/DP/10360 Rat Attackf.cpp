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
		{
			if ((i+cx)<0 or (i+cx)>1024 or (j+cy)<0 or (j+cy)>1024 )
				continue;
			tot+=matriz[i+cx][j+cy];
		}

	return tot;
}

int fil(int cx, int cy)
{
	int tot=0;
	if (cy<0 or cy > 1024) return 0;
	for (int i=-d; i<=d; ++i)
	{	
		if ((cx+i)>1024 or (cx+i)<0) continue;
		tot+=matriz[cx+i][cy];
	}
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
		for (j=0; j<=xt;  ++j)
			for (i=0; i<=yt;  ++i)
				matriz[j][i]=0;

		scanf("%d %d", &d, &n);
		rx=ry=0;
		if (d<0) d=-d;
		while (n--)
		{
			scanf("%d %d %d", &x, &y, &c);
			matriz[x][y]=c;
			xt=xt+x-min(xt,x);
			yt=yt+y-min(yt,y);
		}
		//xt+=d; yt +;

		matados=calcular(0, 0);

		for (j=0; j<=xt;  ++j)
			for (i=0; i<=yt;  ++i)
			{
				if (i==0) anterior=calcular(j, i);
				else anterior=anterior-fil(j,i-d-1)+ fil(j,i+d);
				//if (anterior>=80)
				//	printf("%d %d %d\n",j, i, anterior );
				if (anterior>matados)
				{
					matados=anterior;
					rx=j; ry=i;
				}
			}
		printf("%d %d %d\n",rx, ry, matados );
	}
	return 0;
}