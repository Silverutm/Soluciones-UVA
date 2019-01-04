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
int matriz[4][4]={{0  ,3  ,4  ,5},
				{3  ,6  ,5  ,6},
				{4  ,5  ,4  ,5},
				{5  ,6  ,5  ,6}};
int main()
{
	int a,b,t,x,y;
	cin>>t;
	while (t--)
	{
		cin>>a>>b;
		a=abs(a); b=abs(b);
		x=max(a,b); y=min(a,b);
		if (y==0)
		{
			if (x%4==0)
				cout<<x<<endl;
			else cout<<x+2<<endl;
			continue;
		}
		if (x%4==0 or y%4==0)
		{
			cout<<x+y<<endl;
			continue;
		}
		if (x<=3)
		{
			cout<<matriz[y][x]<<endl;
			continue;
		}
		if (y>=2)
		{
			cout<<x+y<<endl;
			continue;
		}
		if (y==1)
		{
			cout<<x+y+2<<endl;
			continue;
		}

	}
	return 0;
}