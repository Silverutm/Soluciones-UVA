#include <iostream>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	string s;
	int n=1;
	while (cin>>s)
	{
		while (n--) s.pop_back();
		cout<<s<<"\n";
		n=1;
	}
	return 0;
}