#include <bits/stdc++.h>

using namespace std;

#ifdef ACMTUYO
struct RTC{~RTC(){cerr <<"Time: " << clock() * 1.0 / CLOCKS_PER_SEC <<" seconds\n";}} runtimecount;
#define DBG(X) cerr << #X << " = " << X << '\n';
#else
struct RTC{};
#define DBG(X)
#endif

#define fast_io() ios_base::sync_with_stdio(false)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)
typedef long long int number;
const int maxm = 1010;
int pos[maxm];
int cnt[maxm];
int main() {
  int a, c, m, x, q, n;
  while (scanf("%d %d %d %d %d %d", &a, &c, &m, &x, &q, &n) == 6) {
    int nn = n;
    memset(pos, -1, sizeof(pos));
    vector<int> vec;
    vec.pb(x % m);
    pos[x % m] = 0;
    vector<int> cadena, ciclo;
    while (true) {
      int prev = vec[sz(vec) - 1];
      int cur = ((a * prev) % m) + c;
      cur %= m;
      if (pos[cur] == -1) {
        pos[cur] = sz(vec);
        vec.pb(cur);
      } else {
        bool en_ciclo = false;
        for (int e: vec) {
          if (e == cur) {
            en_ciclo = true;
          }
          if (!en_ciclo) {
            cadena.pb(e);
          } else {
            ciclo.pb(e);
          }
        }
        break;
      }
    }
    /*DBG(sz(vec));
    DBG(sz(cadena));
    DBG(sz(ciclo));*/
    memset(cnt, 0, sizeof(cnt));
    if (n <= sz(vec)) {//no da ninguna vuelta al ciclo
      for (int i = 0; i < n; i++) {
        cnt[vec[i]]++;
      }
    } else {
      for (int e: cadena) {
        cnt[e]++;
      }
      n -= sz(cadena);
      int add = n / sz(ciclo);
      for (int e: ciclo) {
        cnt[e] += add;
      }
      n %= sz(ciclo);
      for (int i = 0; i < n; i++) {
        cnt[ciclo[i]]++;
      }
    }
    for (int i = 1; i < maxm; i++) {
      cnt[i] += cnt[i - 1];
    }
    while (q--) {
      int i;
      scanf("%d", &i);
      /*for (int j = 0; j < maxm; j++) {
        if (cnt[j] >= i) {
          printf("%d\n", j);
          break;
        }
      }
      */
      if (cnt[0] >= i) {
        printf("0\n");
      } else {
        assert(cnt[maxm - 1] >= nn);
        int izq = 0, der = maxm - 1;
        while ((der - izq) > 1) {
          int mid = (izq + der) / 2;
          if (cnt[mid] >= i)
            der = mid;
          else
            izq = mid;
        }
        printf("%d\n", der);
      }
    }
  }
  return 0;
}

