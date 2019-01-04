#include<bits/stdc++.h>
using namespace std;
#define tam 105
#define pb push_back
typedef long long ll;
typedef pair <int, int> ii;
typedef vector<int> vi;



int main()
{
    int ma, me, res = 0, x;
    string s;    
    //------------1------------
    /*while(getline(cin, s))    
    {
        stringstream ss(s);
        ss>>ma; me = ma;
        while(ss>>x)
        {
            ma = max(ma, x);
            me = min(me, x);
        }
        res += ma - me;
    }
    cout<<res<<endl;*/


    //------------2------------
    while(getline(cin, s))    
    {
        stringstream ss(s);
        vi v;
        while(ss>>x)
        v.pb(x);

        for (int i=0; i< v.size(); ++i)
            for (int j=0; j< v.size(); ++j)
                if (i!=j)
                    if (v[i]%v[j]==0)
                        res += v[i]/v[j];
    }
    cout<<res<<endl;
    return 0;
}
