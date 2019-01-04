#include <bits/stdc++.h>
using namespace std;
set <long long > s;
int main()
{
	long long n, happy, parcial, cosa, respaldo;
	
	bool b=true;
	while (cin>>n)
	{
		parcial=happy=0;
		s.clear();
		b=true;
		parcial=1;
		respaldo=n;
		s.insert(n);
		if (n!=1)
		while( b==true )
		{
			parcial=0;
			while (n)
			{
				cosa= n%10;
				parcial += cosa*cosa;
				n /=10;
			}
			//printf("%d\n",parcial );
			if ( parcial==1 ) b = false;
			else if ( s.find(parcial)==s.end() )
				s.insert( parcial );
			else b=false;
			n=parcial;
			++happy;
		}
		if (parcial==1)
			printf("happy %d\n", happy);
		else printf("unhappy %d\n", happy);
	}
	return 0;
}