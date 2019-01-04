#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,a ,b ,c ,d, s;
	cin>>n;
	bool k;
	while(n--)
	{
		cin>>a>>b>>c>>d;
		s=a+b+c+d;
		k=false;
		if (  (a<s-a) and (b<s-b) and (c<s-c) and (d<s-d)  )
			k=true;
		if (k) cout<<"Possible\n";
		else cout<<"Impossible\n";
	}
	return 0;
}