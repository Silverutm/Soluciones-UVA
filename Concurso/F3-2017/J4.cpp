#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <cstdint>
using namespace std;

typedef __int128 lld;   //no se puede imprimir pero si manejar

lld gcd(lld a, lld b){
    return ((b == 0) ? a : gcd(b, a % b));
}

inline lld mod_mul(lld a, lld b, lld mod) {
  /*lld x = 0, y = a % mod;   //este es un modulo que cuida numeros muy grandes
  while (b > 0) {             //mejor un int de 128 bits
    if (b & 1)
      x = (x + y) % mod;
    y = (y * 2) % mod;
    b /= 2;
  }
  return x % mod;*/
  return (a * b) % mod; 
}

lld exp(lld a, lld n, lld m) 
{
  lld resultado = 1;
  for (; n; n >>= 1) {
    if (n & 1) resultado =
      mod_mul(resultado, a, m);
      //(resultado % m * a % m) % m;
    a = mod_mul(a, a, m);
    //a = (a % m * a % m) % m;
  }
  return resultado % m;
}


bool witness(lld a, lld n) //
{
  lld u = n - 1;
  int t = 0;
  while (u % 2 == 0)
    t++, u >>= 1;
  lld next = exp(a, u, n);
  if (next == 1) return false;
  lld last;
  for (int i = 0; i < t; ++i) {
    last = next;
    next = mod_mul(last, last, n);
    //next = (last % n * last % n) % n;
    if (next == 1) return last != n - 1;
  }
  return next != 1;
}

bool miller_rabin(lld n) 
{
  int it = 30;    //numero de veces que se intenta verificar que sea primo
  if (n <= 1) return false;
  if (n == 2) return true;
  if (n % 2 == 0) return false;
  for (int i = 0; i < it; ++i) 
  {
    lld a = rand() % (n - 1) + 1;   //tomar un numero en el intervalo
    if (witness(a, n)) return false;  //es primo?
  }
  return true;
}

lld absolut(lld a) {    //valor absoluto
  return (a > 0) ? a: - a;
}

lld pollard_rho(lld n) 
{
  lld x, y, i = 0, k = 2, d;
  x = y = rand() % n; //semilla
  while (1) 
  {
    ++i;
    //x = mod_mul(x, x, n);
    x = (x % n * x % n) % n;
    x += 2;
    if (x >= n) x -= n;
    if (x == y) return 1; //mala semilla
    d = gcd(absolut(x - y), n);
    if (d != 1) return d; //se encontro un factor
    if (i == k) 
    {
      y = x;
      k *= 2;
    }
  }
  return 1;
}

vector<lld> f;
//map<lld, lld> mapa;

void factorize(lld n) 
{
  if (n == 1) return;
  if (miller_rabin(n)) //si es primo
  {
    f.push_back(n);
    //mapa[n]++;
  }
  else 
  {
    lld d = 1;
    while (d == 1)  //obtener dos factores
      d = pollard_rho(n);
    factorize(d);
    factorize(n / d);
  }
}

int main() {
  //ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  //lld asd = 349800000000000LL;
  //asd = asd*10000000000LL + 234;
  //long long popo = asd%1000;
  //cout<<popo<<endl;
  //return 0;
  int t; cin >> t;
  while (t--) 
  {
    unsigned long long int k; 
    cin >> k;
    lld n = k;
    factorize(n);
    sort(f.begin(), f.end());
    for (lld i = 0; i < f.size(); i++)
      (i == f.size() - 1) ? cout << (unsigned long long int)f[i] << '\n' : cout << (unsigned long long int)f[i] << ' ';
    f.clear();
  }
  return 0;
}
/*
5
2
91
40
18055357277566157
9223372036854775807
*/
