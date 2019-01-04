#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;
map <string, int> mapa;
int main()
{
	int n, i, p1, p2, p3;
	string s;
	bool t;
	cin>>n;
	getline(cin, s);
	while (n--)
	{
		getline(cin, s);
		t=true;
		/*i=0;
		while ( i<s.size() -4 and s[i]=='?' ) ++i;
		if ( i==0  ) t=false;
		else if ( s[i]!='M' ) t=false;
		else
		{
			++i;
			//while ( i<s.size()-2 and s[i]=='?') ++i;
			if (s[i]!='?') t=false;
			else if (s[i+1]!='E') t=false;
			else
			{
				++i; ++i;
				while ( i<s.size() and s[i]=='?') ++i;
				if ( i!=s.size() ) t=false;
			}
		}*/
		p1=p2=p3=i=0;
		while ( i<s.size() and s[i]=='?' ) ++i;
		if (  (i >= s.size()-4) or i==0 ) t=false;
		else if (s[i]!='M') t=false;
		else
		{
			p1=i;
			++i;
			while ( i<s.size() and s[i]=='?' ) ++i;
			if (i >= s.size()-2 or i==p1+1) t=false;
			else if (s[i]!='E') t=false;
			else
			{
				p2=i-p1-1;
				++i;
				while ( i<s.size() and s[i]=='?' ) ++i;
				if (i!= s.size() ) t=false;
				else if (p1+p2!= i -2-p1-p2) t=false;
			}
		}
		//cout<<s<<endl;
		if (t) cout<<"theorem\n";
		else cout<<"no-theorem\n";
		//cout<<p1<<" "<<p2<<" "<<i-2<<endl<<endl;
	}
	return 0;
}