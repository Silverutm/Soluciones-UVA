#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;
typedef long long ll; 
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
class UnionFind
{
	private: vi p, rank;
	public:
	UnionFind(int N)
	{
		rank.assign(N, 0);
		p.assign(N, 0);
		for (int i = 0; i < N; i++) 
			p[i] = i; 
	}
	int findSet(int i)
	 { 
	 	return (p[i] == i) ? i : (p[i] = findSet(p[i])); 
	 }
	bool isSameSet(int i, int j) 
	{ 
		return findSet(i) == findSet(j); 
	}
	void unionSet(int i, int j) 
	{
		if (!isSameSet(i, j)) 
		{
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) 
			p[y] = x; // rank keeps the tree short
			else 
			{
			 	p[x] = y;
				if (rank[x] == rank[y]) rank[y]++; 
			}
		}
	 } 
};

int main()
{
	int V, E, P, u, v, w;
	cin>>V>>E>>P;
	
	vector< pair<int, ii> > EdgeList;
	for (int i = 0; i < E; i++) 
	{
		scanf("%d %d %d", &u, &v, &w); 
		EdgeList.push_back(make_pair(w, ii(u, v))); 
	} 
	sort(EdgeList.begin(), EdgeList.end());
	int mst_cost = 0;
	UnionFind UF(V);
	for (int i = 0; i < E; i++) 
	{ 
		pair<int, ii> front = EdgeList[i];
		if (!UF.isSameSet(front.second.first, front.second.second)) 
		{ 
			mst_cost += front.first;
			UF.unionSet(front.second.first, front.second.second); 
		} 
	} 
	printf("$%d\n", P*mst_cost);		
	return 0;
}



