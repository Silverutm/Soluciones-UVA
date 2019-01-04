#include <bits/stdc++.h>
using namespace std;
#define tam 200005
#define pb push_back
#define f first
#define s second
typedef long long ll;
typedef pair<int, int > ii;
typedef vector <int> vi;

vi Lista[tam];
bitset <tam> eliminado;
int vecinos[tam];

int c, p, x, l;
priority_queue<ii, vector<ii>, greater<ii> > pq;
int main()
{
    scanf("%d %d %d %d", &c, &p, &x, &l);
    int a, b;
    while (p--)
    {
        scanf("%d %d", &a, &b);
        Lista[a].pb(b);
        Lista[b].pb(a);

        ++vecinos[a]; ++vecinos[b];
    }
    vecinos[l] = 0;
    pq.push(ii{ 0 , l }); //vecinos que me quedan
    while (not pq.empty())
    {
        auto e=pq.top(); pq.pop();

        if (eliminado[e.s]) continue;

        if ( e.f*2 <= Lista[e.s].size())
        {
            eliminado[e.s] = true;
            for (int v:Lista[e.s])
            {
                --vecinos[v];
                pq.push(ii{ vecinos[v] , v });
            }
        }
    }
    if (eliminado[x])
        cout<<"leave\n";
    else cout<<"stay\n";

    return 0;
}