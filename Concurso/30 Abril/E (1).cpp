#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#define mk make_pair
#define pb push_back()
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair <int, int> ii;
typedef vector < ii > vii;
typedef vector < int > vi;


//char hola[1000009];

int main()
{
	string s;
	int q, i, j;
	while ( cin>>s )
	{
		scanf("%d", &q);
		while (q--)
		{
			scanf("%d %d", &i, &j);
			--i; --j;
			printf("%c\n", s[(i+j)%s.size()]);
		}
	}
	return 0;
}