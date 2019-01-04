#include <iostream>
#include <map>
using namespace std;
int main()
{
	string werty = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./ ~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";
	string vorak = "`123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg' ~!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\"";
	map <char, char> mapa;
	for (int i = 0; i < werty.size(); ++i)
	{
		mapa[ werty[i] ] = vorak[i];
	}
	string s;
	while ( getline( cin, s ) )
	{
		for (auto e: s)
			cout<<mapa[e];
		cout<<endl;
	}
	return 0;
}


