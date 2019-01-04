#include <iostream>
using namespace std;
int main()
{
	string s, copia;
	int i, j;
	bool palindromo;
	while (getline(cin, s) and s!="DONE")
	{
		copia.clear();
		for (auto c:s)
			if (c>='A' and c<='Z') copia.push_back(c-'A'+'a');
			else if (c>='a' and c<='z') copia.push_back(c);
		j=copia.size()/2;
		palindromo=true;
		//cout<<s.size()<<" "<<copia.size()<<" "<<palindromo<<endl;
		for ( i=0; i<j and palindromo; ++i)
			if (copia[i]!=copia[copia.size()-1-i])
				palindromo=false;
		//cout<<palindromo<<endl;
		if (palindromo) cout<<"You won't be eaten!\n";
		else cout<<"Uh oh..\n";
	}
	return 0;
}