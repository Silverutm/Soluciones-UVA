/**
 *    author:  [itmo] enot.1.10
 *    created: 07.01.2017 03:08:03       
**/
#define __USE_MINGW_ANSI_STDIO 0
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),a.end()
#define pw(x) (1LL<<(x))

using namespace std;

typedef long long ll;
typedef double dbl;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int inf = 1.01e9;
const dbl eps = 1e-9;

/* --- main part --- */

const int N = 1e5 + 10;

int a[N];


int main()
{
    #ifdef home
        assert(freopen("1.in", "r", stdin));
        assert(freopen("1.out", "w", stdout));
    #endif
    int tn;
    scanf("%d", &tn);
    forn(tt, tn)
    {
        int n;
        scanf("%d", &n);
        forn(i, n) scanf("%d", &a[i]);
        sort(a, a + n);
        reverse(a, a + n);
        int i = 0, j = n;
        int res = 0;
        while (i < j)
        {
            res++;
            int s = a[i];
            while (s < 50 && i + 1 < j)
            {
                s += a[i];
                j--;
            }
            i++;
            if (s < 50) res--;
        }
        printf("Case #%d: %d\n", tt + 1, res);
    }
            
    #ifdef home
        eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}
