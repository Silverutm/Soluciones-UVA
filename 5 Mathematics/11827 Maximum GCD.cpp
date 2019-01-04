#include <bits/stdc++.h>
using namespace std;
int num[300];
int gcd(int a, int b)
{  return b==0 ? a:gcd(b, a%b); }
int main()
{
    int t, res, n;
    string cad;
    cin>>t;
    getline(cin, cad);
    while (t--)
    {
        stringstream ss; 
        getline(cin, cad);
        ss<<cad;
        n = 0;
        while (ss>>num[n++]);      
        --n;  

        res = 0;
        for(int i=0;i<n; ++i)
            for(int j=i+1;j<n; ++j)            
                res = max(res, gcd(num[i], num[j]) );
        cout<<res<<"\n";
    }
    return 0;
}