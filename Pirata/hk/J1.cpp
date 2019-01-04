#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

#define INF 1000000000
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define FORC(cont, it) for(typeof((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

#define maxN 1001000

struct Node {
	int cnt, l, r, updType, white, isW;
	ll prior;
};

Node tree[maxN];

void push(int n) {
	if (!n) return;
	int v = tree[n].updType & 12;
	if (v) {
		if (v == 4) tree[n].isW = tree[n].white = 0;
		else tree[n].white = tree[n].cnt, tree[n].isW = 1;
		if (tree[n].l) tree[tree[n].l].updType = v;
		if (tree[n].r) tree[tree[n].r].updType = v;
	}
	v = tree[n].updType & 3;
	if (v) {
		if(v&1) swap(tree[n].l, tree[n].r);
		if (v & 2) tree[n].white = tree[n].cnt - tree[n].white, tree[n].isW = !tree[n].isW;
		if (tree[n].l) tree[tree[n].l].updType ^= v;
		if (tree[n].r) tree[tree[n].r].updType ^= v;
	}
	tree[n].updType = 0;
}

void upd_cnt(int n) {
	if (!n) return;
	push(tree[n].l), push(tree[n].r);
	tree[n].cnt = tree[tree[n].l].cnt + tree[tree[n].r].cnt + 1;
	tree[n].white = tree[tree[n].l].white + tree[tree[n].r].white + tree[n].isW;
}

void merge(int &t, int l, int r) {
	push(l), push(r);
	if (!l || !r) t = l ? l : r;
	else if (tree[l].prior > tree[r].prior) merge(tree[l].r, tree[l].r, r), t = l;
	else merge(tree[r].l, l, tree[r].l), t = r;
	upd_cnt(t);
}

void split(int t, int & l, int & r, int key, int add = 0) {
	if (!t) return void(l = r = 0);
	push(t);
	int cur_key = add + tree[tree[t].l].cnt;
	if (key <= cur_key) split(tree[t].l, l, tree[t].l, key, add), r = t;
	else split(tree[t].r, tree[t].r, r, key, cur_key + 1), l = t;
	upd_cnt(t);
}

ii query(int &t, int l, int r, int type)  {
	int t1, t2, t3;
	split(t, t1, t2, l);
	split(t2, t2, t3, r - l + 1);
	tree[t2].updType = type;
	ii ret = ii(tree[t2].cnt - tree[t2].white, tree[t2].white);
	merge(t, t1, t2);
	merge(t, t, t3);
	return ret;
}

int main() {
	int N, M, root, Q, l, r, t;
	while (scanf("%d %d", &N, &M) != EOF) {
		root = 0;
		FOR(i, 1, N+1) {
			tree[i].isW = tree[i].cnt = tree[i].white = 1;
			tree[i].l = tree[i].r = tree[i].updType = 0;
			tree[i].prior = ((ll)rand())<<32LL|rand();
			merge(root, root, i);
		}
		FOR(i, 0, M) {
			scanf("%d %d %d", &Q, &l, &r);
			if (Q == 3) {
				scanf("%d", &t);
				if (t) Q = 8;
				else Q = 4;
			}
			ii ans = query(root, l, r, Q);
			if (!Q) printf("%d %d\n", ans.first, ans.second);
		}
	}
	return 0;
}
