#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;
#define f(i,x,y) for(int i = x; i < y; i ++)
#define ll long long
int a[1005][1005];
int h[1005], le[1005], ri[1005];
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		f(i, 0, n) f(j, 0, m) scanf("%d", &a[i][j]), a[i][j] += 2000 -i - j;
		int best = 0;

		f(j,0,m) h[j] = 1;
		f(i1, 0, n) 
		{
			if (i1)
				f(j, 0, m) h[j] = a[i1][j] == a[i1-1][j]? h[j] + 1 : 1;


			le[0] = -1;
			f(i, 1, m)
			{
				le[i] = i - 1;
				if (h[le[i]] >= h[i] && a[i1][le[i]] == a[i1][i])
				{
					do{
						le[i] = le[le[i]];
					}
					while (le[i] != -1 && h[le[i]] >= h[i] && a[i1][le[i]] == a[i1][i]);
				}
			}

			ri[m - 1] = m;
			for(int i = m-2; i >= 0; i--)
			{
				ri[i] = i + 1;
				if (h[i] <= h[ri[i]] && a[i1][i] == a[i1][ri[i]])
				{
					do{
						ri[i] = ri[ri[i]];
					}
					while (ri[i] != m && h[i] <= h[ri[i]] && a[i1][i] == a[i1][ri[i]] );
				}
			}


			f(i, 0, m)
			{
				int aux = (ri[i] - le[i] - 1) * h[i];
				if (best < aux) best = aux;
			}
		}
		cout << best << endl;
	}
}
