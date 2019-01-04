#include <bits/stdc++.h>
using namespace std;
#define tam 500007
typedef vector <int> vi;
typedef long long ll;
int arr[]={2, 3, 5, 7, 37, 73, 313, 347, 353, 373, 383, 743, 797, 3467, 7643, 34673, 37643, 76367, 79397, 7693967};
int main()
{
	int a, b, t,cont;
	cin>>t;
	while(t--)	
	{
		cin>>a>>b;
		cont = 0;
		for (auto &e:arr)
			if (e>=a and e<=b)
				++cont;
		cout<<cont<<"\n";
	}
	return 0;
}