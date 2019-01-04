#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <set>
#define pb push_back
#define mk make_pair
#define f first
#define s second
using namespace std;
typedef pair <int, int> ii;
typedef vector < int > vi;
typedef vector < ii > vii;
typedef long long ll;

int p[10009], ranko[10009];

//class UnionFind 
//{ // OOP style
//	private: vi p, ranko; // remember: vi is vector<int>
//	public:
void UnionFind(int N) 
{ 
	memset(ranko, 0, sizeof ranko);
	//memset(p, 0, sizeof p);
	for (int i = 0; i < N; i++) 
		p[i] = i; 
}
int findSet(int i) 
{ 
	return (p[i] == i) ? i : (p[i] = findSet(p[i])); 
}
bool isSameSet(int i, int j) 
{ 
	return findSet(i) == findSet(j); 
}
void unionSet(int i, int j) 
{
	if (!isSameSet(i, j)) 
	{ // if from different set
		int x = findSet(i), y = findSet(j);
		if (ranko[x] > ranko[y]) p[y] = x; // ranko keeps the tree short
		else 
		{ 
			p[x] = y;
			if (ranko[x] == ranko[y]) 
				ranko[y]++; 
		}
	}
	return;
} 
//};
//UnionFind UF(2);
int c;
int enemigo[10009];

bool sonamigos(int x, int y)
{
	return isSameSet(x, y);
}

bool sonenemigos(int x, int y)
{
	return enemigo[ findSet(x) ]==findSet(y);
}

bool enemigar(int x, int y)
{
	if ( sonamigos(x,y) ) return false;
	if ( sonenemigos(x,y) ) return true;

	int ex= enemigo[findSet(x)];
	int ey= enemigo[findSet(y)];

	if (ey)
		unionSet(x, ey);
	if (ex)
		unionSet(y, ex);

	enemigo[ findSet(x) ] = findSet(y);
	enemigo[ findSet(y) ] = findSet(x);
	return true;
}


bool amigar(int x,int  y)
{
	if ( sonamigos(x,y) ) return true;
	if ( sonenemigos(x,y) ) return false;

	int ex= enemigo[findSet(x)];
	int ey= enemigo[findSet(y)];

	unionSet(x,y);
	if (ex and ey)
		unionSet(ex,ey);

	if (ey)
		enemigo[ findSet(x) ] = findSet(ey);
	else if (ex)
		enemigo[ findSet(x) ] = findSet(ex);
	
	if ( ey)
		enemigo[ findSet(ey) ] = findSet(x);
	else if (ex)
		enemigo[ findSet(ex) ] = findSet(x);
	return true;
}

//UnionFind clase(int n)
//{
	//return UnionFind(n);
//}

int main()
{
	int x, y, q, n;
	while (scanf("%d %d", &n, &q)==2)
	{
		memset(enemigo, 0, sizeof enemigo);
		UnionFind(n+1);
		while (q--)
		{
			//(!isSameSet(front.second.first, front.second.second)
			//unionSet(front.second.first, front.second.second);

			scanf("%d %d %d", &c,&x, &y);
			++x; ++y;
			if (c==1)
			{
				if (not amigar(x, y) ) printf("-1\n");
			}
			else if (c==2)
			{
				if (not enemigar(x, y) ) printf("-1\n");
			}
			else if (c==3 )
			{
				if ( sonamigos(x, y) ) printf("1\n");
				else printf("0\n");
			}
			else 
			{
				if ( sonenemigos(x, y) ) printf("1\n");
				else printf("0\n");
			}
		}
		//cout<<endl;
	}
	return 0;
}




