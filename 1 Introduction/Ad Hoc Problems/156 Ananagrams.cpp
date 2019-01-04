#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
map <string, string > originalorden;
map <string, int> ordenveces;
int main()
{
	string s, orden;
	int i;
	while (cin>>s and s!="#")
	{
		orden=s;
		for (i=0; i<orden.size(); ++i)
			if (orden[i]>='A' and orden[i]<='Z')
				orden[i]=orden[i]-'A'+'a';
		sort(orden.begin(), orden.end());
		originalorden[s]=orden;
		ordenveces[orden]++;
	}
	for (auto par: originalorden)
		if ( ordenveces[ par.second ]==1 )
			cout<<par.first<<endl;
	return 0;
}