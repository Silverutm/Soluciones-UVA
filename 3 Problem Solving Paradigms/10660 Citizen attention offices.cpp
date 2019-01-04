#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdlib>
#define pb push_back
//#define y second
//#define x first
using namespace std;
//typedef pair <int , int> ii;
typedef vector <int> vi;
//typedef vector < ii > vii;
//vii noceros;

struct ii{
	int x, y, v;
};
vector < ii > noceros;
vi sol;
int res=1000000000, n;

int d(int x1, int y1, int x2, int y2)
{
	return abs(x1-x2)+ abs(y1-y2);
}

void resolver()
{
	int i[6], parcial, tot;
	for (i[1]=0; i[1]<25; ++i[1])
		for (i[2]=i[1]+1; i[2]<25; ++i[2])
			for (i[3]=i[2]+1; i[3]<25; ++i[3])
				for (i[4]=i[3]+1; i[4]<25; ++i[4])
					for (i[5]=i[4]+1; i[5]<25; ++i[5])
					{
						
						tot=0;
						for (auto e:noceros)
						{
							parcial=1000000000;
							for (int j=1;j<=5; ++j )
								//tot+=i[j]*d(e.x,e.y, i[j]%5, i[j]/5);
								parcial=min( parcial, e.v*d(e.x,e.y, i[j]%5, i[j]/5)  );
							tot+=parcial;
						}
						if (tot<res)
						{
							for (int j=1;j<=5; ++j )
								sol[j]=i[j];
							res=tot;
						}
					}
	return ;
}

int main()
{
	int t, i ,a, b, c;
	cin>>t;
	sol.resize(7);
	while (t--)
	{
		noceros.clear();
		cin>>n;
		res=1000000000;
		for (i=0; i<n; ++i)
		{
			cin>>b>>a>>c;
			noceros.pb( ii{a,b, c} );
		}
		resolver();
		cout<<sol[1];
		for (int j=2;j<=5; ++j )
			cout<<" "<<sol[j];
		cout<<endl;
		//cout<<res<<endl;
	}
	return 0;
}