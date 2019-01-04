#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 bi;

#defin tam 107

bi fibo[tam]
int main()
{    
    fibo[0] = 1; fibo[1] = 2;
    for (int i=2; i<tam; ++i)
        fibo[i] = fibo[i-1] + fibo[i-2];

    string s1, s2;
    bi res;    
    while (cin>>s1>>s2)
    {
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());

        res = 0;
        for (int i=0; i<s1.size(); ++i)
            if (s1[i]=='0') res += fibo[i];
        for (int i=0; i<s2.size(); ++i)
            if (s2[i]=='0') res += fibo[i];

        int j = upper_bound(fibo, fibo+tam, res) - fibo - 1;
        cout<<res<<"\n"
        cout<<j<<"\n";
        cout<<fibo[j]<<"\n";
        cout<<fibo[j+1]<<"\n";
        cout<<"\n";

    }
    
    return 0;
}