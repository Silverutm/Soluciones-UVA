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
	string s;
	vi v;
	cin>>s;
	for (int i=0; i<s.size(); i+=2)
		v.pb(s[i]-'0');
	sort(v.begin(), v.end());
	cout<<v[0];
	for (int i=1; i<v.size(); ++i)
		cout<<'+'<<v[i];
	cout<<endl;
	return 0;
}