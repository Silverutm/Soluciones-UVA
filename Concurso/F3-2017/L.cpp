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
    ll n, uno =1LL;
    scanf("%d", &t);
    set <int> conjunto;
    while(t--)
    {
        scanf("%lld", &n);
        bitset<40> bs(n);
        cout<<bs<<endl;
        conjunto.clear();
        ll res = n%(1<<5);
        conjunto.insert(res);
        for(int i=5; i<36;++i)
        {
            res /=2 ;
            if ( n & (uno<<(i%32)) )
                res += 1 << 4;
            //cout<<(n & (uno<<i))<<"   pedazo"<<endl;
            //cout<<((n & (uno<<i)) << 4)<<"   numerito"<<endl;
            conjunto.insert(res);
        }
        if (conjunto.size()==32) printf("yes\n");
        else printf("no\n");
        //for (auto e:conjunto)
        //  cout<<e<<" ";
        //cout<<endl<<endl;
    }
    return 0;
}