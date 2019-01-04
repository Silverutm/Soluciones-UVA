#include <bits/stdc++.h>
#define f first
#define s second
#define mk make_pair
#define pb push_back
#define tam 5001
using namespace std;
typedef long long ll;
typedef pair <int, int> ii;
typedef pair<ll, ll> pll;
typedef vector <int> vi;
typedef vector <vi> vvi;
#define abs_val(a) (((a)>0)?(a):-(a))
//typedef long long ll;
ll mulmod(ll a, ll b, ll c) { // returns (a * b) % c, and minimize overflow
ll x = 0, y = a % c;
while (b > 0) {
if (b % 2 == 1) x = (x + y) % c;
y = (y * 2) % c;
b /= 2;
}
return x % c;
}
ll gcd(ll a,ll b) { return !b ? a : gcd(b, a % b); }
// standard gcd
ll pollard_rho(ll n) {
int i = 0, k = 2;
ll x = 3, y = 3;
// random seed = 3, other values possible
while (1) {
i++;
x = (mulmod(x, x, n) + n - 1) % n;
// generating function
ll d = gcd(abs_val(y - x), n);
// the key insight
cout<<"polar d "<<d<<endl;
cout<<"polar n "<<n<<endl;
if (d != 1 && d != n) return d;
cout<<"polar d "<<d<<endl;
// found one non-trivial factor
if (i == k) y = x, k *= 2;
} }
int main() {
ll n = 2063512844981574047LL;
cin>>n;
// we assume that n is not a large prime
ll ans = pollard_rho(n);
// break n into two non trivial factors
if (ans > n / ans) ans = n / ans;
// make ans the smaller factor
printf("%lld %lld\n", ans, n / ans); // should be: 1112041493 1855607779
}