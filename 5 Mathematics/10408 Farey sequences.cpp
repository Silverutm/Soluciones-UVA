#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int, int> ii;

int gcd(int a, int b)
{  return b==0 ? a:gcd(b, a%b); }
bool mat[1005][1005];
int arr[1005];
int n, k;
vector <ii> v;
bool fu(ii a, ii b)
{
    return a.s*b.f >  b.s*a.f;
}
int main()
{
    int a, b, g;
    n = 1000;
    for (int i=2;i<=n; ++i)
    for (int j=1;j<i; ++j)
    {
        g = gcd(i, j);
        a = j / g; 
        b = i / g;
        if (mat[a][b]) continue;
        mat[a][b] = 1;
        v.push_back(ii{a, b});
    }
    v.push_back(ii{1,1});
    sort(v.begin(), v.end(), fu);

    for (int i = 0; i<v.size();++i)
        if (not arr[v[i].s] )
            arr[v[i].s] = i;
    //for (auto e:v)
    //    cout<<e.f<<"/"<<e.s<<"\n";
    //return 0;
    int c, pos;
    while (cin>>n>>k)
    {
        c = 1;
        pos = arr[n];
        //cout<<pos<<"\n";
        while (c<k)
        {
            ++pos;
            if (v[pos].s <= n) ++c;
        }
        cout<<v[pos].f<<"/"<<v[pos].s<<"\n";
    }
    return 0;
}