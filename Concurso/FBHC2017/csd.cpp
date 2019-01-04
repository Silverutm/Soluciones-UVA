/**
 *    author:  [itmo] enot.1.10
 *    created: 07.01.2017 03:15:16       
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

const int N = 3e4 + 10;

dbl d[N];
dbl d2[N];

dbl calc(int H, int x, int y, int z)
{
//    eprintf("calc %d %d %d %d\n", H, x, y, z);
    memset(d, 0, sizeof d);
    d[0] = 1;
    forn(_, x)
    {
        memset(d2, 0, sizeof d2);
        forn(i, N) for (int j = 1; j <= y; ++j) if (i + j < N) d2[i + j] += d[i] / y;
        forn(i, N) d[i] = d2[i];
    }
    dbl res = 0;
    forn(i, N) if (i + z >= H) res += d[i];
    return res;
}
        


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
        eprintf("test %d\n", tt + 1);
        int H, n;
        scanf("%d%d", &H, &n);
        dbl res = 0;
        forn(_, n)
        {
            char s[11];
            scanf("%s", s);
            int len = strlen(s);
            int pos = -1;
            forn(i, len) if (s[i] == '+') pos = i;
            if (pos != -1)
            {
                int x, y, z;
                sscanf(s, "%dd%d+%d", &x, &y, &z);
                res = max(res, calc(H, x, y, z));
                continue;
            }
            forn(i, len) if (s[i] == '-') pos = i;
            if (pos != -1)
            {
                int x, y, z;
                sscanf(s, "%dd%d-%d", &x, &y, &z);
                res = max(res, calc(H, x, y, -z));
                continue;
            }
            int x, y;
            sscanf(s, "%dd%d", &x, &y);
            res = max(res, calc(H, x, y, 0));
        }
        printf("Case #%d: %.10f\n", tt + 1, res);
    }
            
                    
    #ifdef home
        eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}
