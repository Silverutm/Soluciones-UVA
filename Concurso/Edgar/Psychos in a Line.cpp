#include <bits/stdc++.h>
#define f first
#define s second
#define mk make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair <int, int> ii;
typedef pair<ll, ll> pll;
typedef vector <int> vi;
typedef vector <vi> vvi;
vi v1, v2, v3;

int main()
{
	int n, contador=-1, i, a;
	bool gotkill = true, nex =true;
	cin>>n;
	while (n--)
	{
		cin>>a;
		v1.pb(a);
	}
	while ( gotkill )
	{
		gotkill = false;
		++contador;
		v2.clear();
		//v3.clear();
		if (nex)
		{for (i= v1.size()-2; i>=0; --i )
			if ( v1[i]<v1[i+1] ) v2.pb(v1[i+1]);
			else gotkill=true;}
		else{
		for (i= 1; i< v1.size(); ++i )
			if ( v1[i]<v1[i-1] ) v2.pb(v1[i-1]);
			else gotkill=true;}
		if (gotkill)
		{
			if (nex)
			v2.pb(v1[0]);
			else v2.pb(v1[v1.size()-1]);

			//for (i= v3.size()-1; i>=0; --i )
			//	v2.pb(v3[i]);
			v1=v2;
		}
		nex= not nex;
		//cout <<nex<<endl;
		for (auto e:v1)
			cout<<e<<" ";
		cout<<endl;
	}
	cout<<contador<<endl;
	return 0;
}