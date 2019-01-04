#include <bits/stdc++.h>
using namespace std;
#define tam 500007
typedef vector <int> vi;
typedef long long ll;
string s;
int fi, arr[30];

int f(int n)
{
	//if ( n==0) return 0;
	int &r = arr[n];
	if (r!=-1) return r;
	r = 0;
	for (int i = 0; i < n; ++i)
		//if ((s[i] - 'a' + fi)%26 <= s[n]-'a' or (s[i] - 'a' + fi)%26 <= s[n]-'a' + 26)
		if ( (s[i] - 'a' + fi)%26 <= s[n]-'a' )
			r = max(r, f(i));
	++r;
	return r;
}


int main()
{
	int t;
	cin>>t;
	cout<<(int)'z' - 'a'<<"\n";
	while (t--)
	{
		memset(arr, -1, sizeof arr);
		cin>>s>>fi;		
		cout<<f( s.size() - 1 )<<"\n";
	}
	return 0;
}