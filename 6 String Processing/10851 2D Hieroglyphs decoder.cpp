#include <iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	string s[14];
	while ( t-- )
	{
		getline(cin, s[0] );
		for (int i = 0; i < 10; ++i)
			getline(cin, s[i] );
		for (int j = 1; j < s[0].size() - 1 ; ++j)
		{
			char l = 0;
			for (int i = 1; i < 9; ++i)
			{
				if ( s[i][j]=='\\' )
				l += 1<<(i-1);
			}
			cout<<l;
		}
		cout<<endl;
	}
	return 0;
}