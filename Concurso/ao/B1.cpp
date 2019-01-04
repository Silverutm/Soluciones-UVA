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
	multiset <int> miset;
	for (i=0; i<5; ++i)
		{cin>>a;
				miset.insert(a);}

				for (auto s:miset)
				cout<<s<<" ";
			cout<<endl<<endl;


	auto minimo=miset.begin();
			auto maximo=miset.end();
			maximo--;

			miset.erase(maximo);
			miset.erase(minimo);


				for (auto s:miset)
				cout<<s<<" ";
			cout<<endl<<endl;


			for (i=0; i<5; ++i)
		{cin>>a;
				miset.insert(a);}
minimo=miset.begin();
			 maximo=miset.end();
			maximo--;

			miset.erase(maximo);
			miset.erase(minimo);


				for (auto s:miset)
				cout<<s<<" ";
			cout<<endl<<endl;


	return 0;
}