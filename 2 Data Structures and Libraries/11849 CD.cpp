#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	vector <int> v1, v2;
	int n, m, a, total;
	while (cin>>n>>m and (n or m))
	{
		v1.clear(); v2.clear();
		total = 0;
		
		while (n--)
		{
			cin>>a;
			v1.push_back(a);
		}
		while (m--)
		{
			cin>>a;
			v2.push_back(a);
		}
		
		auto inicio = v2.begin();
		for (auto & e: v1)
		{
			inicio = lower_bound(  inicio, v2.end(), e );
			if (inicio==v2.end() ) break;
			total += *inicio == e ;
		}
		cout<<total<<endl;
	}
	return 0;
}