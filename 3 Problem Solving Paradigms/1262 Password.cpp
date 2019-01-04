#include <bits/stdc++.h>
using namespace std;
//bool letra1[5][30], letra2[5][30];
set <string> posibles, final;
//vector <string> final;
string uno[6], dos[6], sol;
bool revisar;

void crear(int c)
{
	if (c == 5)
	{
		if (revisar)
		{
			if ( posibles.find(sol)!=posibles.end() )
				final.insert(sol);
				//final.push_back(sol);
		}
		else
			posibles.insert(sol);
		return ;
	}
	for (int i = 0; i < 6; ++i)
	{
		if (revisar)
			sol.push_back( dos[i][c] );
		else
			sol.push_back( uno[i][c] );
		crear(c+1);
		sol.pop_back();
	}
}

int main()
{
	int t, k;
	cin>>t;
	while (t--)
	{
		posibles.clear();
		final.clear();

		cin>>k;

		for (int i = 0; i < 6; ++i)
			cin>>uno[i];

		for (int i = 0; i < 6; ++i)
			cin>>dos[i];

		revisar = false;
		crear(0);

		revisar = true;
		crear(0);

		//sort( final.begin(), final.end());

		if (final.size()<k)
			cout<<"NO\n";
		else //cout<<final[k - 1]<<"\n";
		{
			for(auto &e:final)
			{
				--k;
				if (k==0)
				{
					cout<<e<<"\n";
					break;
				}
			}
		}
	}
	return 0;
}