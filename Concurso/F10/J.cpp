#include <bits/stdc++.h>
#define pb emplace_back()
#define x first
#define y second

using namespace std;
typedef long long ll;
typedef vector <int > vi;
typedef pair <int, int> ii;

int matriz[1005][1005], f, c;
ii profundo[1005][1005];

void resolver(int fi, int col)
{
	
}

int main()
{
	int i, j;
	for (i = 0; i <= f; ++i) matriz[i][0]=-1;
	for (i = 0; i <= c; ++i) matriz[0][i]=-1;
	while (scanf("%d %d", &f, &c)==2)
	{
		for (i = 1; i <= f; ++i)
			for (j = 1; j <= c; ++j)
				scanf("%d", &matriz[i][j]);
		resolver(f, c);
	}

}