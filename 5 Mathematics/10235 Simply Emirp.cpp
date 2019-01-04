#include <bits/stdc++.h>
using namespace std;

bool esprimo(int n)
{
    if (n==1) return false;
    int raiz = sqrt(n);
    for (int i = 2; i<=raiz; ++i)
        if (n%i == 0) return false;
    return true;
}

bool ermip(int n)
{
    int k = 0, copia = n;
    while (n)
    {
        k = 10*k + n % 10;
        n /= 10;
    }
    if (copia == k) return false;
    return esprimo(k);
}

int main()
{
    int n;
    bool primo, reves;
    while (cin>>n)    
    {                
        primo = esprimo(n);
        if (primo and n>9)
            reves = ermip(n);
        else reves = false;

        if (not primo) cout<<n<<" is not prime.\n";
        else if (reves) cout<<n<<" is emirp.\n";
        else cout<<n<<" is prime.\n";
    }
    return 0;
}