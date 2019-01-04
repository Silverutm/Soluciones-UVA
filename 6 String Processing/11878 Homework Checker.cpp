#include <iostream>
#include <cctype>
using namespace std;
int main()
{
	int tot=0, n1, n2, n3, res, i;
	string s;
	char op;
	while (cin>>s)
	{
		n1=n2=n3=res=0;
		if ( s[ s.size()-1 ]=='?' ) continue;
		i=0;
		while ( isdigit(s[i]) )
		{
			n1 *= 10;
			n1 += s[i]-'0';
			++i;
		}
		op = s[i];
		++i;
		while ( isdigit(s[i]) )
		{
			n2 *= 10;
			n2 += s[i]-'0';
			++i;
		}

		++i;
		while ( i<s.size() and isdigit(s[i]) )
		{
			n3 *= 10;
			n3 += s[i]-'0';
			++i;
		}

		if (op=='-')
			res= n1-n2;
		else
			res=n1+n2;
		if (res==n3) ++tot;
		//cout<<n3<<" "<<res<<endl;
	}
	cout<<tot<<endl;
	return 0;
}