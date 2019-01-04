#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
using namespace std;
int b[5000006], m;
string s, s1;
void kmpPreprocess()
{
	int i=0, j=-1; b[0]=-1;
	while (i<m)
	{
		while ( j>=0 and s1[i]!=s1[j] ) j=b[j];
		++i; ++j;
		b[i] = j;
	}
}

int main()
{
	//stringstream w("dj sd ");
	/*stringstream w;
	string x;
	w<<"hola que haces como estas "<<25<<" "<<45;
	w<<" hoa ";
	while (w>>x)
		cout<<x<<endl;
	w.clear();
	w<<"dofi sadoijf oisad o odisd os o sodi";
	while (w>>x)
		cout<<x<<endl;
	return 0;*/	
	int tam;
	while (getline(cin, s))
	{
		s1.clear();
		memset(b, 0, sizeof b);
		m=2*s.size()+1;
		
		
		for (int i = s.size()-1; i >= 0; --i)
			s1.push_back(s[i]);
		s1.push_back('#');
		s1 += s;
		kmpPreprocess();
		tam = b[s1.size()-1];
		cout<<s;
		for (int i = (int)s.size()-tam-1-1; i >=0 ; --i)
			cout<<s[i];
		cout<<endl;
		//cout<<s1<<endl;
		/*for (int i = 0; i < m; ++i)
			printf("%2d ",b[i] );
		printf("\n");
		for (auto e:s)
			printf(" %c ", e);
		printf("\n\n");*/
	}
	return 0;
}