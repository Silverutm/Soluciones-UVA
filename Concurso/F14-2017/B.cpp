#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector <int> vi;
#define tam 105


int main()
{
    int n, i, a, res;
    set <int> miset;
    while (scanf("%d", &n)==1)
    {
        miset.clear();
        for (i =0; i<n; ++i)
        {
            scanf("%d", &a);
            res = 0;
            while (a)                
            {
                res |= 1LL<<(a%10);
                a /= 10;
            }
            miset.insert(res);
        }
        printf("%d\n", (int)miset.size());
    }
    return 0;
}