#include<bits/stdc++.h>

using namespace std;

int main()
{
	int T,x,k,suma;
	cin>>T;
	for(int i=0;i<T;i++) 
	{
		cin>>x>>k;
		suma=0;
		int r=sqrt(x);
		for(int j=1;j<=r;j++) 
		{
			if(x%j==0) 
			{
				if(j%k!=0)
					suma+=j;
				if((x/j)%k!=0 && j!=x/j)
					suma+=(x/j);
			}
		}
		cout<<suma<<"\n";
	}
	return 0;
}