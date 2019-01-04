#include <iostream>
using namespace std;
int escaleras[105], jugadores[1000009];
int main()
{
	int t, n, v, d, i, dado, a, b;
	cin>>t;
	while (t--)
	{
		cin>>n>>v>>d;
		for (i=1; i<=100; ++i) escaleras[i]=i;
		//for (i=100; i<=300; ++i) escaleras[i]=100;
		for (i=0; i<n; ++i) jugadores[i]=1;
		for (i=1; i<=v; ++i)
		{
			cin>>a>>b;
			escaleras[a] = b;
		}
		i=0;
		bool fin=false;
		while (d--)
		{			
			cin>>dado;
			if (fin) continue;
			jugadores[i] +=dado;
			
			jugadores[i] = jugadores[i]>100 ? 100: jugadores[i];
			jugadores[i] = escaleras[ jugadores[i] ];
			if (jugadores[i]==100) fin=true;
			//while ( escaleras[ jugadores[i] ]!=jugadores[i] )
				
			i=(i+1)%n;
		}
		for (i=0; i<n; ++i)
			cout<<"Position of player "<<i+1<<" is "<<jugadores[i]<<".\n";
	}
	return 0;
}