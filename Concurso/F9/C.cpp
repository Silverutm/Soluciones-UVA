#include <bits/stdc++.h>
using namespace std;
struct co
{
	int y1, x1, y2, x2;
};
vector < co > matriz[3][3];
int main()
{
	matriz[1][1] = {co{1,1,1,1}, co{1,2,1,2}, co{1,3,1,3}, 
					co{2,1,2,1}, co{2,2,2,2}, co{2,3,2,3}, 
					co{3,1,3,1}, co{3,2,3,2}, co{3,3,3,3}};
	
	matriz[1][2]= { co{1,1,1,2}, co{1,2,1,3},
					co{2,1,2,2}, co{2,2,2,3},
					co{3,1,3,2}, co{3,2,3,3}};

	matriz[1][3]= { co{1,1,1,2}, co{1,2,1,3},
					co{2,1,2,2}, co{2,2,2,3},
					co{3,1,3,2}, co{3,2,3,3}};
	for (auto e: matriz[1][1])
		cout<<e.x1<<endl;

	return 0;
}