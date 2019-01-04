#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
ll _sieve_size;
bitset<10000010> bs;
vi primes;

void sieve(ll upperbound) 
{
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= upperbound; i++) if (bs[i]) 
    {
        for (ll j = i * i; j <= upperbound; j += i) bs[j] = 0;
        primes.push_back((int)i);

    } 
}

int n, raiz;
//k tamano del subconjunto
//n el numero
ll mul_abajo = 1;
ll res = 0;
void libre_cuadadrados(int i,int usados)
{    
    //hacer
    res +=  (usados&1 ? -1:1) *n / mul_abajo;

    for (int w = i; primes[w] <= raiz; ++w)
    {
        mul_abajo *= primes[w] * primes[w];
        if (mul_abajo > n)
        {
            mul_abajo /= primes[w] * primes[w];
            return ;    
        }        
        libre_cuadadrados(w + 1, usados + 1);
        mul_abajo /= primes[w] * primes[w];
    }

}

int inf = 1, sup = 2000000001;
int z;

void busqueda()
{
    int cont = sup - inf, i, salto;
    while (cont > 0)
    {
        i = inf; salto = cont>>1; i += salto;
        n = i;
        raiz = sqrt(n);
        res = 0;        
        libre_cuadadrados(0, 0);
        if (res < z)
        {
            inf = ++i;
            cont -= salto + 1;
        }
        else cont = salto;
    }
    cout<<inf<<"\n";
}

int main()
{
    sieve(100001);
    
    cin>>z;
    busqueda();
//    raiz = sqrt(n);
  //  res = 0;        
//    libre_cuadadrados(0, 0);

    //cout<<res<<"\n";
    return 0;
}

/*1
2
3
4-----
5
6
7
8-------
9----------
10
11
12-------
13
14
15
16--------
17
18--------
19*/