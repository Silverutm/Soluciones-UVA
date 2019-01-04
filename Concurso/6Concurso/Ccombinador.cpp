#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s[300];
	int i=-1,j;
	while (getline (cin, s[++i]));
	for (i=0; i<100;i+=1 )
	{
		for (auto c: s[i])
			printf("%c", c);
		printf("\n");

		for (auto c: s[i+100])
			printf("%c", c);
		printf("\n");
	}
	return 0;
}