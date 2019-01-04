#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	freopen("A.in", "r", stdin);
	string s;
	while (cin>>s)
		cout<<s<<endl;
	fclose(stdin);

	cin.clear();

	freopen("A.out", "r", stdin);	
	while (cin>>s)
		cout<<s<<endl;
	fclose(stdin);
}