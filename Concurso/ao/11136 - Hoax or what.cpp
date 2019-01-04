#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;
int main()
{
	 std::cout.sync_with_stdio(false);
	int d, suma, a, ini, k, i, maxi, mini, imaxi, imini, j;
	//priority_queue<int> mayor;
	//priority_queue<int,vector<int>,greater<int> > menor;
	multiset <int> miset;
	while (cin>>d and d)
	{
		suma=0;
		//while (!mayor.empty()) mayor.pop();
		//while (!menor.empty()) menor.pop();
		miset.clear();
		for (i=0; i<d; ++i)
		{
			//ini=2*i;
			cin>>k;
			while (k--) 
			{
				cin>>a;
				miset.insert(a);
			}
			//for (auto s:miset)
			//	cout<<s<<" ";
			//cout<<endl;
			//continue;
			//sort (mivector.begin(), mivector.end() );
			auto minimo=miset.begin();
			auto maximo=miset.end();
			--maximo;
			suma+= *maximo-*minimo;

			miset.erase(maximo);
			miset.erase(minimo);
			
			//mivector[imaxi]=-1;
			//mivector[imini]=-1;
		}
		cout<<suma<<endl;
	}
	return 0;
}