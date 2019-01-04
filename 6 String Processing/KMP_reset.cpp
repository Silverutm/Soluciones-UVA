#include <iostream>
using namespace std;
string s, s2;
int b[100];
void preproceso()
{
	int i=0, j=-1; b[0]=-1;
	while ( i<s.size() )
	{
		while (j>=0 and s[i]!=s[j]) j=b[j];
		++i; ++j;
		b[i] = j;
	}
}

void kmp()
{
	int i=0, j=0;
	while ( i<s2.size() )
	{
		while (j>=0 and s2[i]!=s[j]) j=b[j];
		++i; ++j;
		if (j==s.size())
		{
			cout<<"Lo logramos en "<<i-j<<endl;
			j = b[j];
		}
	}
}

int main()
{
	
	while (cin>>s>>s2)
	{
		preproceso();
		cout<<" ";
		for (auto e: s)
			cout<<e<<" ";
		cout<<endl;
		for (int i = 0; i < s.size(); ++i)
			cout<<b[i]<<" ";
		cout<<endl<<endl;
	}
	return 0;
}