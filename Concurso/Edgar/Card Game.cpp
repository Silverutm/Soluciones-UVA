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
bool mayor(char a, char b)
{
	//9", "T", "J", "Q", "K" and "A
	if (a=='A' and b!=a) return 1;
	if (b=='A' ) return 0;

	if (a=='K' and b!=a) return 1;
	if (b=='K' ) return 0;

	if (a=='Q' and b!=a) return 1;
	if (b=='Q' ) return 0;

	if (a=='J' and b!=a) return 1;
	if (b=='J' ) return 0;

	if (a=='T' and b!=a) return 1;
	if (b=='T' ) return 0;

	return a>b;

}

int main()
{
	string s1,s2,s3;
	cin>>s1>>s2>>s3;
	if ((s2[1]==s3[1] and mayor(s2[0],s3[0]) ) or (s2[1]==s1[0] and s2[1]!=s3[1]))
		cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}