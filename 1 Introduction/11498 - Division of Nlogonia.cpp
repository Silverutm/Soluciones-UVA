#include <cstdio>
using namespace std;
int main()
{
	int k, n, m, x, y;
	while (scanf("%d", &k) and k)
	{
		scanf("%d %d", &n, &m);
		while(k--)
		{
			scanf("%d %d", &x, &y);
			if (x>n and y>m) printf("NE\n");
			else if (x>n and y<m) printf("SE\n");
			else if (x<n and y<m) printf("SO\n");
			else if (x<n and y>m) printf("NO\n");
			else printf("divisa\n");
		}
	}
	return 0;
}