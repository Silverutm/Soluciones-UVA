#include <bits/stdc++.h>
using namespace std;
//look at my code my code is amazing
#define FOR(i, a, b) for (int i = int(a); i < int(b); i++)
#define FOREACH(it, a) for (typeof(a.begin()) it = (a).begin(); it != (a).end(); it++)
#define ROF(i, a, b) for (int i = int(a); i >= int(b); i--)
#define REP(i, a) for (int i = 0; i < int(a); i++)
#define INF 1000000000
#define INFLL 1000000000000000000LL
#define ALL(x) x.begin(), x.end()
#define MP(a, b) make_pair((a), (b))
#define X first
#define Y second
#define EPS 1e-9
#define DEBUG(x)   cerr << #x << ": " << x << " "
#define DEBUGLN(x) cerr << #x << ": " << x << " \n"
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef long long ll;
typedef vector<bool> vb;

bool isvowel(const char &c)
{
	return (c == 'a' or c == 'e' or c == 'i'  or c == 'o'  or c == 'u');
}

int main()
{
	string s, ps;//parsed s
	while(cin >> s)
	{
		if (s.size()>50 ) cout<<"mococososmaos\n\nghg";
		ps.clear();
		for(char &c: s)
		{
			if(isvowel(c))
				ps += c;
		}
		bool ispossible = true;
		int n = ps.size(); 
		REP(i, n / 2)
		{
			if(ps[i] != ps[n-i-1])
			{
				ispossible = false;
				break;
			}
		}
		printf("%c\n", ispossible?'S':'N');

	}
	return 0;
}