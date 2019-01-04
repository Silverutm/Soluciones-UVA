#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAX_N 1010
#define MAX_W 40

int i, T, G, ans, N, MW, V[MAX_N], W[MAX_N], memo[MAX_N][MAX_W], id[MAX_N];

int value(int id, int w) {
  if (id == N || w == 0) return 0;
  if (memo[id][w] != -1) return memo[id][w];
  if (W[id] > w)         return memo[id][w] = value(id + 1, w);
  return memo[id][w] = max(value(id + 1, w), V[id] + value(id + 1, w - W[id]));
}

int main() {
  char c1, c2;
  T=1;
  scanf("%d", &MW);
  while (T--) {
    memset(memo, -1, sizeof memo);
    i=0;
    while(scanf("%d", &id[i]), getchar(), scanf("%d", &V[i]), getchar(), scanf("%d", &W[i]) )
      ++i;
      

    ans = 0;
    
    
      
      ans += value(0, MW);

    printf("%d\n", ans);
  }

  return 0;
}