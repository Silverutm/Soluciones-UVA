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
ll  n,k;
int esmenor(int v)
{
	ll res=0, div=1;
	while (v/div)
	{
		//v /=div;
		res += v/div;
		div *= k;
	}
	//cout<<v<<" "<<res<<endl;
	return res < n;
}
int limite(int ini,int fin)
{
	int v, c, s;
	c=fin-ini;
	while ( c > 0 )
	{
		v=ini; s=c/2; v+=s;
		if ( esmenor(v))
		{
			ini=v+1;
			c -=s+1;
		}
		else
			c=s;
	}
	return ini;
}

/*

count = distance(first,last);
  while (count>0)
  {
    it = first; step=count/2; advance (it,step);
    if (*it<val) {                 // or: if (comp(*it,val)), for version (2)
      first=++it;
      count-=step+1;
    }
    else count=step;
  }
  return first;
}
*/

int main()
{
	cin>>n>>k;
	cout<<limite(1,n+1);
	return 0;
}