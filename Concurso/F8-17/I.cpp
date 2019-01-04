#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n, raiz, i;
    cin>>n;
    raiz  = sqrt(n) + 1;
    for (i=2;i<=raiz;++i)
        if(n%i==0)
        {
            while(n%i==0) n/=i;
            if (n==1) cout<<"yes\n";
            else cout<<"no\n";
            return 0;
        }
    if (n-1)
    cout<<"yes\n";
    else cout<<"no\n";
    return 0;
}