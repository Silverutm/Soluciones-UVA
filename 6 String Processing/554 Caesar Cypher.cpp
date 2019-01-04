#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
using namespace std;

string sumar(string s, int k)
{
	for (auto & c:s)
	{
		if (isalpha(c))
			c = c- 'A' +1;
		else c=0;
		c =(c+ k)%27;
		if ( c )
			c+='A'-1;
		else c=' ';
	}
	return s;
}
string s, dic[105];
int w;
string siguiente()
{
	string ss;
	ss.clear();
	while(w<s.size() and s[w]!=' ')
	{
		ss.push_back(s[w]);
		++w;
	}
	if ( ss.empty() ) {++w; ss=" ";}
	return ss;
}

int main()
{	
	int n=0, maxi, rm, p, k;
	while (getline( cin, s) and s!="#")
	{
		dic[n++]=s;
	}	
	getline( cin, s);
	maxi = 0; rm = 0;
	for (k=0; k<=26; ++k)
	{
		p=0;
		for (int i = 0; i < n; ++i)
		{
			if ( strstr( s.c_str()  ,sumar(dic[i], k).c_str() )!=NULL )
				++p;
		}
		if (p>rm) {maxi=k;rm=p;}
	}
	for (auto & c:s)
	{
		if (isalpha(c))
			c = c- 'A' +1;
		else c=0;
		c =(c- maxi + 27)%27;
		if ( c )
			c+='A'-1;
		else c=' ';	
	}
	//cout<<s<<endl;
	/*int c=0;
	string sub;
	for (w = 0; w < s.size(); )
	{
		sub = siguiente();
		if ( c+sub.size()>60 )
		{
			c= 0;
			cout<<endl;
		}
		c += sub.size();
		if (sub ==" " and c==1)
		{
			--c;
			continue;
		}
		if (sub==" " and c==60 )
			continue;
		cout<<sub;
	}*/
	//cout<<s<<endl;
	for (int i = 60; i < s.size(); i+= 61)
	{
		while (s[i]!=' ') { /*cout<<s[i];*/ --i;}
		//cout<<endl;
		s[i]='\n';
	}

	while (s[s.size()-1]==' ') s.pop_back();
	cout<<s<<endl;
	return 0;
}