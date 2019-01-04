#include <iostream>
#include <cstring>
using namespace std;
int arr[55], i, z, mini;
int mayor(int a, int b)
{
	if (a==-1) return a;
	return a>b ? a:b;
}

int f(int a, int b)
{
	return a>b ? 0:1;
}

int siguiente(int a)
{
	for (i=a+1; i<=53;++i)
		if (arr[i]==0) return i;
}

void fun(int a, int b, int c, int x, int y)
{
	int v=f(a,x)+f(b,y);
	if ( v==2 ) z=mayor(z,mini);
	else if ( v ) z=mayor(z, siguiente(c));
	else z=-1;
	return;
}

int main()
{	
	int a, b, c, x,y;
	while(cin>>a>>b>>c>>x>>y and a)
	{
		memset(arr, 0, sizeof arr);
		arr[a]=arr[b]=arr[c]=arr[x]=arr[y]=1;
		for(i=1; i<=52; ++i)
			if (arr[i]==0)
			{
				mini=i;
				break;
			}
		z=0;

		fun(a,b,c,x,y);
		fun(a,b,c,y,x);
		fun(a,c,b,x,y);
		fun(a,c,b,y,x);
		fun(c,b,a,x,y);
		fun(c,b,a,y,x);
		if (z==53) z=-1;
		cout<<z<<endl;
	}
	return 0;
}