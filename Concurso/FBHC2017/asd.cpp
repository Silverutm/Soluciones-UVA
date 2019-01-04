/**
 *    author:  [itmo] enot.1.10
 *    created: 07.01.2017 02:58:23       
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
        printf("Case #%d: ", tt + 1);
        dbl p, x, y;
        scanf("%lf%lf%lf", &p, &x, &y);
        p = p / 100 * 360;
        dbl d = sqrt((x - 50) * (x - 50) + (y - 50) * (y - 50));
        int ok = 0;
        if (p > 0 && d < 50 + eps)
        {
            dbl alp = atan2(x - 50, y - 50) / acos(-1) * 180;
            while (alp < -eps) alp += 360;
            if (alp < p + eps) ok = 1;
        }
        if (ok) printf("black\n");
        else printf("white\n");
    }
        
        
    #ifdef home
        eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}
