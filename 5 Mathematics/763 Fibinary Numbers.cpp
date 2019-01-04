#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 bi;

#define tam 107

bi fibo[tam];
string s1, s2, cad;

void atras(int i)
{
    cad[i]='0';  cad[i+1]='0';
    cad[i-1]='1';
    if (cad[i-2]=='1')
        atras(i-2);
    return ;
}

void limpiar()
{
    for (int i=0; i<cad.size()-1; ++i)
        if (cad[i]=='1' and cad[i+1]=='1')
            atras(i);
}

int main()
{    
    fibo[0] = 1; fibo[1] = 2;
    for (int i=2; i<tam; ++i)
        fibo[i] = fibo[i-1] + fibo[i-2];
    
    bi res;    
    bool imp = false;
    while (cin>>s1>>s2)
    {
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());

        res = 0;
        for (int i=0; i<s1.size(); ++i)
            if (s1[i]=='1') res += fibo[i];
        for (int i=0; i<s2.size(); ++i)
            if (s2[i]=='1') res += fibo[i];

        int j = upper_bound(fibo, fibo+tam, res) - fibo - 1;
        //cout<<(ll)res<<"\n";
        //cout<<j<<"\n";
        //cout<<(ll)fibo[j]<<"\n";
        //cout<<(ll)fibo[j+1]<<"\n";
        //cout<<"\n";

        cad = "0000";
        while (j>=0)
        {
            if (res - fibo[j] >= 0)
            {
                cad.push_back('1');
                res = res - fibo[j];
            }
            else cad.push_back('0');
            --j;
        }

        limpiar();
        reverse(cad.begin(), cad.end());
        while (cad[cad.size()-1]=='0') cad.pop_back();
        reverse(cad.begin(), cad.end());
        if (imp) cout<<"\n";
        if (cad.empty()) cout<<"0\n";
        else cout<<cad<<"\n";
        imp = true;
    }
    
    return 0;
}