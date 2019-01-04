//Ara 250
//Abraham 210
//Pablo 3000
#include<bits/stdc++.h>
using namespace std;
#define tam 105
#define pb push_back
typedef long long ll;
typedef pair <int, int> ii;
typedef vector<int> vi;



int main()
{
    string s;
    cin>>s;    
    //------------1------------
    int res = 0;
    for (int i=0; i<s.size(); ++i)
        if (s[i] == s[(i+1)%s.size()])
            res += s[i] - '0';
    cout<<res<<endl;


    //------------2------------
    res = 0;
    for (int i=0; i<s.size(); ++i)
        if (s[i] == s[(i+s.size()/2)%s.size()])
            res += s[i] - '0';
    cout<<res<<endl;
    return 0;
}
