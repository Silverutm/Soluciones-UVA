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

int k, n, raiz;
//k tamano del subconjunto
//n el numero
bool posible;
ll parcial;
ll mul_abajo = 1;

ll libre_cuadadrados(int i, int usados)
{
    if (usados == k)
        //hacer
    if (primes[i]> raiz)
        posible = false;

    for (int w = i; primes[w] <= raiz; ++w)
    {
        mul_abajo *= primes[w];
        libre_cuadadrados(i + 1, usados + 1);
        mul_abajo /= primes[w];
    }

}

int main()
{
    sieve(10000001);
    
    cin>>n;
    raiz = sqrt(n);

    posible = true;
    k = 2;
    parcial = 0;
    while(posible)
    {
        libre_cuadadrados(0)
        ++k;
    }
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