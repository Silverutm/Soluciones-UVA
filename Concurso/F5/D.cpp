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

int main()
{
	ll t, n;
	cin>>t;
	while (t--)
	{
		cin>>n;
		cout<<1+n*(n-1)/2+n*(n-1)*(n-2)*(n-3)/24<<endl;;
	}
	return 0;
}