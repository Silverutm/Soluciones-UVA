#include <bits/stdc++.h>
using namespace std;
#define tam 100000005
double fact[tam];
int main()
{
    fact[2] = log10(2);
    for (int i=3; i< tam; ++i)
        fact[i] = fact[i-1] + log10(i);

    int n, k;
    while (cin>>n>>k)
    {
        //if (n>=tam or k>=tam) return 0;
        cout<<(long long)floor(fact[n] - fact[k] - fact[n - k]) +1<<"\n";
    }
    return 0;
}