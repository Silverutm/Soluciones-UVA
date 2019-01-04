#include <bits/stdc++.h>
//#include <vector>
#define pb emplace_back()
#define pair <int, int> ii;
typedef long long ll;
//typedef vector<int> vi;

using namespace std;
int main()
{
	int t;
	vector <int> a={1,2,3,4,5}, b={2,3,4,5,6}, v;
	v=a;
	cin>>t;
	while (t--)
	{
		for (int i = 0; i < 5; ++i)		
			 cin>>v[i];
		if (v==a or v== b)
			printf("Y\n");
		else printf("N\n");
	}
	return 0;
}