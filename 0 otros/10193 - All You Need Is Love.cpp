#include <iostream>
#include <cstdio>
using namespace std;

int convertir( string s)
{
	int t=1, res=0, i;
	for (i=s.size()-1; i>=0; --i)
	{					
		if (s[i]=='1')
			res +=t;

		t = t<<1;
	}
	return res;
}

int gcd(int a, int b)
{
	return b==0 ? a:gcd(b, a%b);
}

int main()
{
	string s1, s2;
	int t1, t2, c=0, n;
	scanf("%d", &n);
	bitset <30> s1, s2;
	for (c=0; c<n;)
	{
		cin>>s1>>s2;
		t1= convertir(s1);
		t2=convertir(s2);
		printf("Pair #%d: ", ++c);

		if (gcd(t1, t2)>1) printf("All you need is love!\n");
		else printf("Love is not all you need!\n");
	}
	return 0;
}