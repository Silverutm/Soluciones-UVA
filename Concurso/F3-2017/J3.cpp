#include <bits/stdc++.h>
#define f first
#define s second
#define mk make_pair
#define pb push_back
#define tam 5001
using namespace std;
typedef  long long ll;
typedef pair <int, int> ii;
typedef pair<ll, ll> pll;
typedef vector <int> vi;
typedef vector <vi> vvi;
multiset<ll> salida;
void checar(ll n);
void es_primo(ll n);
ll mulmod(ll a, ll b, ll c);
void imprimir()
{
    bool b = false;
    for (auto &e:salida)
    {
        if (b)
        cout<<' '<<e;
        else
        {
            cout<<e;
            b=true;
        }
    }
    cout<<'\n';
}

ll fastpow( ll a, ll n, ll mod )
{
    ll res=1;
    a = a % mod;
    while ( n )
    {
        if ( n&1 )
            res=mulmod(res,a,mod);
        a = mulmod(a,a,mod);
        n >>=1;
    }
    return res;
}

bool miillerTest(ll d, ll n)
{
    // Pick a random number in [2..n-2]
    // Corner cases make sure that n > 4
    ll a = 2 + rand() % (n - 4);
 
    // Compute a^d % n
    int x = fastpow(a, d, n);
 
    if (x == 1  || x == n-1)
       return true;
 
    // Keep squaring x while one of the following doesn't
    // happen
    // (i)   d does not reach n-1
    // (ii)  (x^2) % n is not 1
    // (iii) (x^2) % n is not n-1
    while (d != n-1)
    {
        x = mulmod(x,x,n);
        d <<= 1;
 
        if (x == 1)      return false;
        if (x == n-1)    return true;
    }
 
    // Return composite
    return false;
}
 
// It returns false if n is composite and returns true if n
// is probably prime.  k is an input parameter that determines
// accuracy level. Higher value of k indicates more accuracy.
bool isPrime(ll n)
{    
    // Corner cases
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;
    // Find r such that n = 2^d * r + 1 for some r >= 1
    ll d = n - 1;
    while ( (d & 1) == 0)
        d >>= 1;
 
    // Iterate given nber of 'k' times
    for (int i = 0; i < 100; i++)
         if ( miillerTest(d, n) == false)
              return false;
 
    return true;
}
 
ll _sieve_size;
bitset<1000010> bs;
vi primes;
ll li, li2;
void sieve(ll upperbound) 
{

    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) 
    {
        for (ll j = i * i; j <= _sieve_size; j += i) 
            bs[j] = 0;
        primes.push_back((int)i);
    } 
}

ll primeFactors(ll N) 
{
    //vi factors;
    //ll res = 1, parcial;    
    ll PF_idx = 0, PF = primes[PF_idx]; // primes has been populated by sieve   
    while (PF * PF <= N) 
    {
        //parcial = 1;        
        while (N % PF == 0) 
        { 
            N /= PF; 
            //parcial *=PF;
            salida.insert(PF);
            //factors.push_back(PF); 
        }
        //parcial = ( parcial*PF - 1 )/(PF-1);
        //res *=parcial;

        PF = primes[++PF_idx];
    }
    if (N != 1) //factors.push_back(N);
    {
        //res *= (N*N-1)/(N-1);
        salida.insert(N);
    }
    //return res;
}
// Driver program

/*ll mulmod(ll a, ll b, ll c) 
{ // returns (a * b) % c, and minimize overflow
    ll x = 0, y = a % c;
    while (b > 0) 
    {
        if (b % 2 == 1) 
            x = (x + y) % c;
        y = (y * 2) % c;
        b /= 2;
    }
    return x % c;
}*/
#define abs_val(a) (((a)>0)?(a):-(a))
ll gcd(ll a,ll b) 
{ return !b ? a : gcd(b, a % b); }
ll mulmod(ll a, ll b, ll c) { // returns (a * b) % c, and minimize overflow
ll x = 0, y = a % c;
while (b > 0) {
if (b % 2 == 1) x = (x + y) % c;
y = (y * 2) % c;
b /= 2;
}
return x % c;
}
// standard gcd
ll pollard_rho(ll n) {
    //cout<<"polar "<<n<<endl;
int i = 0, k = 2;
ll x = 3, y = 3;
// random seed = 3, other values possible
set<ll> semillas;
while (1) {
i++;
x = (mulmod(x, x, n) + n - 1) % n;
while(semillas.find(abs_val(y - x))!=semillas.end())
{
    x = rand()%n;
    y = rand()%n;
}
semillas.insert(abs_val(y - x));
// generating function
//cout<<"x "<<x<<endl;
ll d = gcd(abs_val(y - x), n);
//cout<<"polar d "<<d<<endl;
//cout<<"polar n "<<n<<endl;
//return 0;
// the key insight
if (d != 1 && d != n) return d;
//cout<<"polar d "<<d<<endl;
// found one non-trivial factor
if (i == k) y = x, k *= 2;
} }

void es_primo(ll n)
{
    /*if (n<=li)
    {
        if ( bs[n] )
            salida.insert(n);
        else
            primeFactors(n);            
    }
    else
    {
        if ( isPrime(n) )
            salida.insert(n);
        else
        {
            checar(n);            
        }
    }*/

    if (n<=li2)
    {
        if (n<=li)
        {   
            if ( bs[n] )
                salida.insert(n);                    
            else
                primeFactors(n);                    
        }
        else
        {
            primeFactors(n);                
        }
    }
    else
    {
        if ( isPrime(n) )
            salida.insert(n);
        else
            checar(n);            
    }
}

void checar(ll n)
{
    ll x, y;
    //cout<<"polar ro\n";
    //return ;
    if (n==4)
    {
        salida.insert(2);salida.insert(2);
        return;
    }
    if (n==6)
    {
        salida.insert(2);salida.insert(3);
        return;
    }
    if (n==12)
    {
        checar(4);checar(3);
        return;
    }
    if (isPrime(n))
    {
        salida.insert(n);
        //cout<<n<<" es primo\n";

        return;
    }
    //cout<<n<<"no es primo\n";
    //return;
    x = pollard_rho(n);

    y = n/x;
    checar(x); checar(y);
}
int main()
{        
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //sieve(1000000); 
    //li = 1000000;
    //li2 = (ll)primes[primes.size()-1]*(ll)primes[primes.size()-1];
    //ll ca = primes[primes.size()-1];
    //cout<<ca<<"  ca\n";
    //cout<<li2<<endl;
    int t;
    ll n;
    //scanf("%d", &t);
    cin>>t;
    while (t--)
    {
        salida.clear();
        //scanf("%lld", &n);
        cin>>n;

        checar(n);
        imprimir();
    } 
    return 0;
}