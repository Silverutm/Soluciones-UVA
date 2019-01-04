#include <iostream>
#include <string>
using namespace std;
int l, k, r;
string s, sub;
string convertir()
{
	string r=sub;
	int i;
	for (i=0; i<sub.size(); i++)
		r[(i+k)%sub.size()]=sub[i];
	return r;
}

void meter()
{
	int i;
	for (i=0; i<sub.size(); i++)
		s[l+i-1]=sub[i];
	return ;
}	

int main()
{
	int m;
	cin>>s;
	cin>>m;
	while (m--)
	{
		cin>>l>>r>>k;
		sub=s.substr(l-1, r-l+1);
		sub=convertir();
		meter();
	}
	cout<<s<<endl;
	return 0;
}