#include <bits/stdc++.h>
using namespace std;
int main()
{	
	string s, f;
	while (getline(cin,f) and f!="#")
	{
		s=f;
		next_permutation(f.begin(),f.end());
		if (f<=s)  cout<<"No Successor\n";
		else cout<<f<<endl;
	}
	return 0;
}