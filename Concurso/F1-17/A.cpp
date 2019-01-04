#include <bits/stdc++.h>
#define f first
#define s second
#define mk make_pair
#define pb push_back
#define tam 105
using namespace std;
typedef long long ll;
typedef pair <int, int> ii;
typedef pair<ll, ll> pll;
typedef vector <int> vi;
typedef vector <vi> vvi;

ll m1[tam][tam], m2[tam][tam];
set <ll> miset;
int main()
{
	int h, w, b;
	scanf("%d %d %d", &w, &h, &b);

	for (int i = 0; i < h; ++i)	
		for (int j = 0; j < w; ++j)		
			scanf("%lld", &m1[i][j]);

	for (int a = 0; a < b; ++a)			
	{
		for (int i = 0; i < h; ++i)	
		for (int j = 0; j < w; ++j)
		{
			int i1 = i-1, j1 = j-1, i2=i+1, j2=j+1;
			for (; i1 <= i2; ++i1)
				for (j1 = j-1; j1 <= j2; ++j1)
					m2[i][j] += m1[(i1+h)%h][(j1+w)%w];			
		}

		for (int i = 0; i < h; ++i)	
		for (int j = 0; j < w; ++j)
		{
			m1[i][j] = m2[i][j];
			m2[i][j] = 0;
		}

		

		//for (int i = 0; i < h; ++i,cout<<endl)	
		//for (int j = 0; j < w; ++j)
			//cout<<m1[i][j]<<" ";
	}

	for (int i = 0; i < h; ++i)	
		for (int j = 0; j < w; ++j)
			/*if (m1[i][j])*/ miset.insert(m1[i][j]);

	printf("%d\n",(int)miset.size() );

	return 0;
}