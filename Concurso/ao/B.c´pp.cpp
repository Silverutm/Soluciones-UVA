#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int d, suma, a, ini;
	vector <int> mivector;
	while (cin>>d and d)
	{
		suma=0;
		mivector.clear();
		for (i=0; i<d; ++i)
		{
			ini=2*i;
			cin>>k;
			while (k--) 
			{
				cin>>a;
				v.push_back(a);
			}
			sort (mivector);
			suma+= mivector[mivector.size()-1] -mivector[ini];
			mivector[ini]=-1;
			mivector[mivector.size()-1]=-1;
		}
		cout<<suma<<endl;
	}
	return 0;
}