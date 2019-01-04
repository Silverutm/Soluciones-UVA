#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;

int main()
{
	int n, a, b;
	ll r=1;
	while (scanf("%d,%d,%d", &n, &a, &b)==3)
	{
		if (a==b) printf("0\n");
		else cout<< (r<<n)-1<<"\n";
	}
	return 0;
}