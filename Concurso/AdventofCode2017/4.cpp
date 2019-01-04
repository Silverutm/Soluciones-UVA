#include<bits/stdc++.h>
using namespace std;
#define tam 105
#define pb push_back
typedef long long ll;
typedef pair <int, int> ii;
typedef vector<int> vi;

int main()
{
    
    string s, a;
    int n, res = 0;
    set<string> miset;
    //------------1------------
    while (getline(cin, s))
    {
        stringstream ss(s);
        n=0; miset.clear();
        while(ss>>a)
        {
            ++n;
            //------------2------------
            sort(a.begin(), a.end());

            miset.insert(a);
        }
        res += n == (int)miset.size();        
    }
    cout<<res<<endl;
    
    
    return 0;
}
