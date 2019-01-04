#include <iostream>
using namespace std;
int main()
{
	string s;
	std::ios::sync_with_stdio(false);
	int contador = 0;
	while (cin>>s)
	{
		for (auto &c:s)
		{
			if ( c>='a' and c<= 'z')
				++contador;
		}
	}
	cout<<contador<<"\n";
	return 0;

}