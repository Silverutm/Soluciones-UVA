#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <ll> vi;
int main()
{
    vi vc, vx;
    ll coef, equis, res, pot;  
    bool imp;
    string c, x;  
    while ( getline(cin, c) and getline(cin, x))
    {
        vc.clear(); vx.clear();
        stringstream sc, sx;
        sc<<c; sx<<x;
        while(sc>>coef) vc.push_back(coef);
        while(sx>>equis) vx.push_back(equis);

        reverse(vc.begin(), vc.end());
        imp = false;
        for (ll &equis:vx)
        {
            res = 0;        
            pot = 1;
            for (int i=0; i<vc.size(); ++i)
            {
                res += vc[i]*pot;                
                pot *= equis;
            }
            if (imp) cout<<" ";
            cout<<res;
            imp = true;
        }
        cout<<"\n";
    }
    return 0;
}