#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	string s1, s2;
	int i, t;
	char temp;
	cin>>t;
	cout<<t<<"\n";
	getline(cin,s1);
	while (t--)
	{
		getline(cin,s1);
		getline(cin,s2);
		i=-1;
		for (auto c:s1)
		{
			if (c==' ') temp=c;
			else temp=(c-'a'+s2[(++i)%s2.size()]-'a')%26+'a';
			printf("%c", temp);
		}
		printf("\n");
		for (auto c:s2)
			printf("%c", c);
		printf("\n");
	}
	return 0;
}