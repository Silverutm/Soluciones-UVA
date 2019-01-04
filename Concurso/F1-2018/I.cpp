#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector <ii> vii;
typedef long long ll;
#define pb push_back

#define tam 15

int main()
{
    int n, h[tam], t, i, res, mod;
    scanf("%d", &n);
    for (i=0; i<n; ++i)
        scanf("%d", &h[i]);
    scanf("%d", &t);

    res = h[0]; mod = t%h[0];
    for (i=1; i<n; ++i)
        if (t%h[i] < mod)
        {
            res = h[i];
            mod = t%h[i];
        }
    printf("%d\n", res);
    return 0;
}