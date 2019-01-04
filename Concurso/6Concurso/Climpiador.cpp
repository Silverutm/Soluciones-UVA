#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	while (getline (cin, s))
	{
		for (auto c:s)
		{
			if (not isalpha(c) and c!=' ') continue;
			printf("%c", tolower(c));
		}
		printf("\n");
	}
	return 0;
}