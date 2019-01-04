#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <vector>
#include <bitset>
#include <map>
#include <cmath>
#include <queue>
#define f first
#define s second
#define mk make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair <int, int> ii;
typedef pair<ll, ll> pll;
typedef vector <int> vi;
typedef vector <vi> vvi;
int main()
{
	vi hola({4,7,77,74,47,44,777,774,747,477,744,474,447,444});
	int n;
	cin>>n;
	for (auto & e:hola)
	{
		if (n%e==0)
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}