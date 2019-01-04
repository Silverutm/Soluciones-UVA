#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, w, h;
int tabla[10005][105];

int f(int cant, int i)
{
    if (i == w) return 1;
    int &res = tabla[cant][i];
    if (res != -1) return res;
    
    int z = min(cant, h);
    res = 0;
    for (int w = 0; w<= z; ++w)
    {
        res = (res + f(cant - w, i + 1))%1000000007;
    }
    return res;
}

int main()
{
    memset(tabla, -1, sizeof tabla);
    scanf("%d %d %d", &n, &w, &h);
    int x = f(n, 0);
    int z = n/w + 1;
    z = min(z, h + 1);
    x = (x - z + 1000000007) %1000000007;
    printf("%d\n", x);
    return 0;
}