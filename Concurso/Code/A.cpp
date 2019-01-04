#include <bits/stdc++.h>
using namespace std;

bool veri(int m, int mini, int k)
{
	bool pp=false;
	for(int i=1 ; i<=m;i++)
	{
				if(k==i*mini){
					pp=true;
					return pp;
				}
	}
	return pp;
}
int main(int argc, char const *argv[])
{
	int c;
	cin>>c;
	while(c--){
		int m,n,k;
		cin>>m>>n>>k;
		int mini=min(m,n);
		if(k>=m*n)
		{
				cout<<"0"<<endl;
			}
		else if(veri(m,mini,k))
		{
			cout<<mini*mini<<endl;
		}

		else
			cout<<mini*mini+1<<endl;

	}
	return 0;
}	