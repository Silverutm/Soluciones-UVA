#include <iostream>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	string s, s1;	
	getline(cin,s);
	while (cin>>s1>>s)
		cout<<s<<"\n";			
	return 0;
}