#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
char cosas[500];
int main()
{
	string s, s2;
	getline(cin,s);
	getline(cin,s2);
	istringstream iss(s);
	while (iss>>s)
	{
		if ( cosas[s[0]] ) continue;
		cosas[s[0]]=s[2];
	}
	for (auto e: s2)
		if (isalpha(e))
		{
			char c= toupper(e);
			c=cosas[c];
			if (e>='A' and e<='Z')
				cout<<(char)toupper(c);
			else cout<<(char)tolower(c);
		}
		else cout<<e;
	return 0;	
}