#include<bits/stdc++.h>
using namespace std;
#define tam 105
#define pb push_back
typedef long long ll;
typedef pair <int, int> ii;
typedef vector<int> vi;

int main()
{
    int x=0, y=0;
    string s;
    set<ii> miset(ii{x,y});
    cin>>s;
    for (char c:s)
    {
        if (c=='^')
            --y;
        else if (c=='v')
            ++y;
        else if (c=='>')
            ++x;
        else --x;
        miset.insert(ii{x,y});
    }
    cout<<miset.size()<<endl;

    return 0;
}
