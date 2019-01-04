#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

int distancia(int x1, int y1,int x2, int y2 )
{
	return abs(x1-x2)+ abs(y1-y2);
}

int main()
{
	int i, n, t, k, x1, y1, g, contador,x, y;
	vector < pair<int, int> > dis_clas;
	cin>>t;
	while (t--)
	{
		dis_clas.clear();
		contador=0;
		cin>>x>>y;
		cin>>n;
		for (i=0; i<n; ++i)
		{
			cin>>x1>>y1>>g;
			dis_clas.push_back(  make_pair(distancia(x,y, x1,y1), g) );
		}
		cin>>k;
		sort (dis_clas.begin(), dis_clas.end());
		for (i=0; i<k; ++i)
			if ( dis_clas[i].second )
				++contador;

		if (contador > k-contador)
			cout<<"Guapa rules"<<endl;
		else cout<<"Lars\n";
	}
	return 0;
}
