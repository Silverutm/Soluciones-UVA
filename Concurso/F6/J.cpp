#include <iostream>
#include <algorithm>
#include <set>
#include <bitset>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <vector>
#include <queue>

#define pb push_back
#define k first
#define d second
#define mk make_pair
using namespace std;
typedef long long ll;
typedef pair < int,int > ii;
typedef vector < int > vi;
typedef vector < ii > vii;
typedef vector < vi > vvi;

vi nums;
int main()
{
	int n, a;
	while (cin>>n)
	{
		nums.clear();
		while(n--)
		{
			cin>>a;
			nums.pb(a);
		}
		a=*max_element(nums.begin(), nums.end());
		cout<<a/100<<"."<<(a-a/100*100)/10<<a%10<<"000\n";
	}
	return 0;
}