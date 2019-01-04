#include <bits/stdc++.h>
using namespace std;

string f(string sentence)
{
    stringstream ss;
    string s, s_ans;
    int l_ans = 0;
    ss<<sentence;
    
    while(ss>>s)
        if (not ( s.size()&1 )  )
            if ( s.size() > l_ans )
            {
                l_ans = s.size();
                s_ans = s;
            }

    if ( l_ans )
        return s_ans;
    return "00";
}

int main()
{
    string s;
    getline(cin, s);
    //cout<<s<<endl;
    cout<<f(s)<<"\n";
    return 0;
}
