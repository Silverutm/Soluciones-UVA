#include <bits/stdc++.h>
#define f first
#define s second
//#define tam 200005
using namespace std;
typedef long long ll;
//typedef pair<ll,ll> ii;

int cambio_base(ll n, int b)
{
    int res = 0;
    while(n)
    {
        res += n%b;
        n /=b;
    }
    return res;
}

int main()
{	
	ll n, ant;
    int a, b, x, y;
    scanf("%lld %d %d", &n, &a, &b);
    
    do 
    {
        ++n;
        n = min(n + (a - n%a)%a, n + (b - n%b)%b );
        x = cambio_base(n, a);
        y = cambio_base(n, b);
        //cout<<x<<" "<<y<<"\n";
    } while(x!=y);
    printf("%lld\n", n);
	return 0;
}