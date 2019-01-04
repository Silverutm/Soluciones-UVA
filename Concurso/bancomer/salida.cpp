#include <iostream>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	string s;
	while (getline(cin, s))
	{
		for (auto &c:s)
			if (c=='|') printf("&c", ',');
			else printf("%c", c);
		printf(",\n");

	}
}