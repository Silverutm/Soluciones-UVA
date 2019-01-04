#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

#define clr(a, b) memset(a, b, sizeof(a))
#define f(a, b, c) for(int a = b; a < c; a++)
typedef long long ll;

#define N 1002
int par[N];
int freqs[N];

int main() {
	int a, c, m, x, q, n;
	while(scanf("%d %d %d %d %d %d", &a, &c, &m, &x, &q, &n) == 6) 
	{
		f(i, 0, m) par[i] = -2;
		par[x] = -1;
		ll cur = x;
		vector<int> tail, cycle;
		while(true) 
		{
			ll sig = (cur * a + c) % m;
			if (par[sig] == -2) 
			{
				par[sig] = cur;
				cur = sig;
			} else 
			{
				int pos = par[sig];
				while(pos != -1) 
				{
					tail.push_back(pos);
					pos = par[pos];
				}

				pos = cur;
				while(pos != par[sig]) 
				{
					cycle.push_back(pos);
					pos = par[pos];
				}
				break;
			}
		}
		reverse(tail.begin(), tail.end());
		reverse(cycle.begin(), cycle.end());

		clr(freqs, 0);
		f(i, 0, min((int)tail.size(), n)) freqs[tail[i]]++;
		n -= tail.size();
		n = max(n, 0);
		if (n) 
		{
			int full = n / cycle.size();
			f(i, 0, cycle.size()) freqs[cycle[i]] += full;
			n -= full * cycle.size();
			f(i, 0, n) freqs[cycle[i]]++;
		}
		//f(i, 0, m) cout << i << " " << freqs[i] << endl;
		f(i, 1, m) freqs[i] += freqs[i - 1];
		while(q--) 
		{
			int pos; scanf("%d", &pos);
			printf("%d\n", (int)(lower_bound(freqs, freqs + m, pos) - freqs));
		}

	}
}
