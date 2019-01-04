#include <bits/stdc++.h>
#define f first
#define s second
#define mk make_pair
#define pb push_back
#define tam 105
using namespace std;
typedef long long ll;
typedef pair <int, int> ii;
typedef pair<ll, ll> pll;
typedef vector <int> vi;
typedef vector <vi> vvi;

int main()
{
    int t;
    ll n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lld", &n);
        printf("%lld\n", n*n+2*n);
    }
    return 0;
}