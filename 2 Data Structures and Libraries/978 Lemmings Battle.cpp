#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int casos, n, m, rondas, a;
	priority_queue<int> colan, colam;
	int batallan[100005], batallam[100000];
	cin>>casos;
	while (casos--)
	{
		cin>>rondas>>n>>m;
		while (n--)
		{
			cin>>a;
			colan.push(a);
		}
		while (m--)
		{
			cin>>a;
			colam.push(a);
		}
		while( colan.size() and colam.size())
		{
			
			rondas = min(rondas, min((int)colam.size(), (int)colan.size()));
			for (int i = 0; i < rondas; ++i)
			{
				batallan[i] = colan.top(); colan.pop();
				batallam[i] = colam.top(); colam.pop();
			}
			for (int i = 0; i < rondas; ++i)
			{
				if (batallan[i] > batallam[i] ) colan.push(batallan[i] - batallam[i]);
				else if (batallan[i] < batallam[i] ) colam.push(-batallan[i] + batallam[i]);
			}
		}
		if (colan.size() + colam.size() ==0 ) cout<<"green and blue died\n";
		else if ( colan.size()  )
		{
			 cout<<"green wins\n";
			 while (!colan.empty())
			 {	cout<<colan.top()<<endl; colan.pop(); }
		}
		else 
		{
			 cout<<"blue wins\n";
			 while (!colam.empty())
			 {	cout<<colam.top()<<endl; colam.pop(); }
		}
		if (casos) cout<<"\n";
	}
	return 0;
}