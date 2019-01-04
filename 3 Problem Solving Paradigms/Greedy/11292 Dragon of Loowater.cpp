#include <cstdio>
#include <algorithm>
using namespace std;
int dragon[30000], knights[30000], d, k;
int main()
{
	int i, j, total;
	while (scanf("%d %d", &d, &k) && (d or k) )
	{
		total=0;
		for (i=0; i<d; ++i)
			scanf("%d", &dragon[i]);

		for (i=0; i<k; ++i)
			scanf("%d", &knights[i]);

		sort(dragon, dragon+d);
		sort(knights, knights+k);

		for(i=j=0; i<d && j<k; )
		{
			if ( dragon[i]<=knights[j] )
			{
				total+=knights[j];
				++i;
			}
			++j;
		}
		if (i<d) printf("Loowater is doomed!\n");
		else printf("%d\n", total);
	}
	return 0;
}