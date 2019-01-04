#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;
int main()
{
	int a, b, c;
	cin>>a>>b>>c;
	if (!c )
	{
		if (a==b) printf("YES\n");
		else printf("NO\n");
	}
	else if ((b-a)%c) printf("NO\n");
	else if ((b-a)/c < 0) printf("NO\n");
	else printf("YES\n");
	return 0;
}