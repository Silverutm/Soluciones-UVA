#include <iostream>
using namespace std;
int res;
string T, P;
int b[5000006], m, n;
void kmpPreprocess()
{
	int i=0, j=-1; b[0]=-1;
	while (i<m)
	{
		while ( j>=0 and P[i]!=P[j] ) j=b[j];
		++i; ++j;
		b[i] = j;
	}
}

void kmpSearch() 
{ 
	int i = 0, j = 0; 
	while (i < n) 
	{ 
		while (j >= 0 && T[i] != P[j]) j = b[j];
		i++; j++;
		if (i==n) res += (m-j);
		if (j == m) 
		{ 
			//printf("P is found at index %d in T\n", i - j);
			j = b[j]; 
		} 
	}
}


int main()
{
	int t, w, k; 
	cin>>t;
	while (t--)
	{
		cin>>w>>k;
		
		if ( k==0 ) {cout<<"0\n"; continue; }
		if (k==1) {cin>>T; cout<<T.size(); continue;}
		cin>>T;
		res= T.size();
		for (int i = 1; i < k; ++i)
		{			
			cin>>P;
			if (T==P) continue;

			//proceso
			n=T.size();
			m=P.size();
			kmpPreprocess();
			kmpSearch();

			T=P;
		}
		cout<<res<<endl;
	}
	return 0;
}