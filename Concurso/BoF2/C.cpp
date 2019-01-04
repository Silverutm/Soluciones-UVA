#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;
typedef long long ll; // comments that are mixed in with code
typedef pair<int, int> ii; // are aligned to the right like this
typedef vector<ii> vii;
typedef vector<int> vi;
class UnionFind { // OOP style
private: vi p, rank; // remember: vi is vector<int>
public:
UnionFind(int N) { rank.assign(N, 0);
p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
void unionSet(int i, int j) {
if (!isSameSet(i, j)) { // if from different set
int x = findSet(i), y = findSet(j);
if (rank[x] > rank[y]) p[y] = x; // rank keeps the tree short
else { p[x] = y;
if (rank[x] == rank[y]) rank[y]++; }
} } };

int main()
{
	int V, E, P, u, v, w;
	cin>>V>>E>>P;
	// inside int main()
	vector< pair<int, ii> > EdgeList; // (weight, two vertices) of the edge
	for (int i = 0; i < E; i++) 
	{
	scanf("%d %d %d", &u, &v, &w); // read the triple: (u, v, w)
	EdgeList.push_back(make_pair(w, ii(u, v))); } // (w, u, v)
	sort(EdgeList.begin(), EdgeList.end()); // sort by edge weight O(E log E)
// note: pair object has built-in comparison function
	int mst_cost = 0;
	UnionFind UF(V); // all V are disjoint sets initially
	for (int i = 0; i < E; i++) { // for each edge, O(E)
	pair<int, ii> front = EdgeList[i];
	if (!UF.isSameSet(front.second.first, front.second.second)) { // check
	mst_cost += front.first; // add the weight of e to MST
	UF.unionSet(front.second.first, front.second.second); // link them
	} } // note: the runtime cost of UFDS is very light
// note: the number of disjoint sets must eventually be 1 for a valid MST
printf("$%d\n", P*mst_cost);		
	return 0;
}



