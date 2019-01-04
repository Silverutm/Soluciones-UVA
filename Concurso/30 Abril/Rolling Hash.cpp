Rolling Hash
const int MAXN = (int)6*(1e5)+10; // size of the biggest string
const ll mod1 = (ll) INF + 7, mod2 = (ll) INF + 9; // big primes which P*p < 2**64
ll p1[MAXN], p2[MAXN];
ll radix1 = 271, radix2 = 277; //small primes > size of alfabet
pair<ll, ll> hashea(const string& cadena)
{
4
pair<ll, ll> hash = MP(0, 0);
REP(i, cadena.size())
{
hash.X = ( hash.X + (cadena[i] * p1[i]) % mod1 ) % mod1;
hash.Y = ( hash.Y + (cadena[i] * p2[i]) % mod2 ) % mod2;
}
return hash;
}
void preprocess()
{
p1[0] = 1;
p2[0] = 1;
FOR(i, 1, MAXN)
{
p1[i] = p1[i-1];
p1[i] = (p1[i] * radix1) % mod1;
p2[i] = p2[i-1];
p2[i] = (p2[i] * radix2) % mod2;
}
}
4.