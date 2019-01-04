#include <iostream>
using namespace std;
string s, a="+x";

void menos()
{
	if (s[0]=='+') s[0]='-';
	else s[0]='+';
}

int main()
{
	int t;
	while (cin>>t and t)
	{
		--t;
		a="+x";
		while (t--)
		{
			cin>>s;
			if (s=="No") continue;
			else if (a=="+x") a=s;
			else if (a=="-x") {menos(); a=s;}
			else if (a==s) a="-x";
			else if (a[1]==s[1]) a="+x";	
			//cout<<a<<endl;	

		}
		cout<<a<<endl;
	}
	return 0;
}