#include <cstdio>
#include <sstream>
#include <set>
#include <vector>
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define clr(a, b) memset(a, b, sizeof(a))
#define f(a, b, c) for(int a = b; a < c; a++)
typedef long double ld;
typedef long long ll;
#define N 1000002
#define C 26

int DP[N][C];
char s[N];

int main () {
  vector<ll> F;
  F.push_back(1);
  F.push_back(1);
  while(true) {
    ld a = F[F.size() - 1];
    ld b = F[F.size() - 2];
    ll c = a + b;
    ld d = a + b;
    if (c != d) break;
    F.push_back(c);
  }
  set<string> S;
  f(i, 0, F.size()) f(j, 0, F.size()) if (i != j) {
    ostringstream os;
    os << F[i] << F[j];
    S.insert(os.str());
  }
  vector<string> fibs(S.begin(), S.end());

  while(scanf("%s", s) == 1) {
    int n = strlen(s);
    f(j, 0, C) DP[n][j] = n;
    for(int i = n - 1; i >= 0; i--) {
      f(j, 0, C) DP[i][j] = DP[i + 1][j];
      char c = s[i];
      if (c >= '0' && c <= '9') {
        DP[i][c - '0'] = i;
      }
    }
    
    int res = 0;
    f(i, 0, fibs.size()) {
      string t = fibs[i];
      int pos = 0;
      bool valid = true;
      f(j, 0, t.size()) {
        int c = t[j] - '0'; 
        pos = DP[pos][c];
        if (pos == n) {
          valid = false;
          break;
        }
        pos++;
      }
      res += valid;
    }
    printf("%d\n", res);
  }

}
