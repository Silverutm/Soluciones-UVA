#include <iostream>
#include <vector>
using namespace std;

struct estatements
{
	int a, b;
	bool v;
};

vector <estatements> s;
estatements d;

int main()
{
	int n, t, m, uno=1, N, cont, p;
	char c;
	
	cin>>t;
	for (int caso = 1; i <= t; ++caso)
	{
		s.clear();
		cin>>n>>m;
		while (m--)
		{
			cin>>d.a>>d.b>>c;
			d.v = c=='T' ? true:false;
			s.push_back(d);
		}
		N = uno<<n;
		cont = 0;
		for (int i = 0; i < N; ++i)
		{
			p = 1;
			for (auto & e: s)
				if ( e.v )
				{
					if ( i &  )
				}

		}
	}
	return 0;
}