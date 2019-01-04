#include <iostream>
#include <algorithm>
using namespace std;
int matriz[1002][1002], caso[1002][1002], ca=5;
string s;
int max_subseq_pal(int l, int r)
{
	int &res = matriz[l][r], &vuelta=caso[l][r];

	if (vuelta==ca) return res;
	vuelta = ca;
	if (l==r) return res=1;
	if (l+1==r) return res = s[l]==s[r] ? 2:1;
	if (s[l]==s[r]) return res = 2 + max_subseq_pal(l+1, r-1);
	return res= max( max_subseq_pal(l+1,r), 
				max_subseq_pal (l, r-1)
		);

}

int main()
{
	int t;
	cin>>t;
	getline(cin, s);
	while (t--)
	{
		getline(cin, s);
		if (s=="") cout<<"0\n";
		else 
		cout<<max_subseq_pal(0, s.size())<<"\n";
		++ca;
	}
	return 0;
}