#include<bits/stdc++.h>
using namespace std;
#define tam 1505
#define pb push_back
typedef long long ll;
typedef pair <int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

map<string, int> mapa;
string s, var, ins, elif, varcond, cond;
int valsum, valcond;

bool secumple()
{
    if (cond == "==")
        return mapa[varcond] == valcond;
    if (cond == "!=")
        return mapa[varcond] != valcond;
    if (cond == ">")
        return mapa[varcond] > valcond;
    if (cond == ">=")
        return mapa[varcond] >= valcond;
    if (cond == "<")
        return mapa[varcond] < valcond;
    if (cond == "<=")
        return mapa[varcond] <= valcond;
}

int main()
{
    //------------1------------
    int maxi = 0;
    while(getline(cin, s))
    {
        stringstream ss(s);
        ss>>var>>ins>>valsum>>elif>>varcond>>cond>>valcond;

        if ( secumple() )
        {
            if (ins == "dec")
                valsum = -valsum;
            
            mapa[var] += valsum;

            //------------2------------
            maxi = max(maxi, mapa[var]);    
        }
    }
    
    //------------2------------
    //maxi = mapa[var];
    //for (auto par:mapa)
    //    maxi = max(maxi, par.second);
    cout<<maxi<<endl;
    return 0;
}
