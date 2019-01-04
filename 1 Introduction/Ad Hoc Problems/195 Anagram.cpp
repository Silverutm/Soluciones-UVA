#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	cin>>t;
	string s;
	while (t--)
	{
		cin>>s;
		for (int i=0; i<s.size(); ++i)
		{
			if (s[i]>='A' and s[i]<='Z')
				s[i]=(s[i]-'A')*2;
			else s[i]=(s[i]-'a')*2+1;

		}
		sort( s.begin(), s.end() );
		do
		{
			for (auto c:s)
				if (c%2==0) printf("%c", c/2+'A');
				else printf("%c", (c-1)/2+'a');
			cout<<endl;
		} while (next_permutation( s.begin(), s.end() ));
	}
	return 0;
}