#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
int main()
{
	int limite = 128;
	vi uno, dos;
	for (int n = 1; n <= limite; ++n)
	{
		uno.clear(); dos.clear();
		for (int i = 1; i <= n; ++i)
			uno.push_back(i);

		int z = 0;
		while(uno.size()!=1)
		{
			dos.clear(); int j;
			for (j = z; j < uno.size(); j += 2)
				dos.push_back(uno[j]);			

			if (j - 2 == uno.size() -1 )
				z = 1;
			else z = 0;

			uno = dos;
		}
		printf("%2d: %d\n",n,uno[0] );
	}
	return 0;
}