#include <iostream>
#include <vector>
using namespace std;
vector <int> Lista[1000006];
int main()
{
	int n, m, k, v, a;
	while (cin>>n>>m)
	{
		for (int i = 0; i < 1000006; ++i)
			Lista[i].clear();
		for (int i = 1; i <= n; ++i)
		{			
			cin>>a;
			Lista[a].push_back(i);
		}
		while (m--)
		{
			cin>>k>>v;
			--k;
			if ( k<Lista[v].size() )
				cout<<Lista[v][k]<<endl;
			else cout<<"0\n";
		}
	}
	return 0;
}