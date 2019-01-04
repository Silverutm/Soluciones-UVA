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
    int t, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        int res = 1;
        int raiz = sqrt(n);
        for (int i=2; i<= raiz; ++i)
            if (n%i==0)
                res +=i + n/i;

        if (raiz*raiz==n) res-=raiz;
        if (res==n) printf("perfect\n");
        else if (res<n) printf("deficient\n");
        else printf("abundant\n");
    }
    return 0;
}