#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <set>
#define pb push_back
#define mk make_pair
#define f first
#define s second
using namespace std;
typedef pair <int, int> ii;
typedef vector < int > vi;
typedef vector < ii > vii;
typedef long long ll;

double x, y, yp[509], xp[509], yg;
int n;

bool revisa(int j, int i)
{
	int k=j;
	do
	{
		k=(j+1)%n;
	}while (xp[j]==xp[k]);
	if ( (xp[i]>x and xp[k]>x) or (xp[i]<x and xp[k]<x) )
		return 0;
	return 1;
}

int dentro()
{
	int  conta=0,i, j;
	if (x==xp[0] and y==yp[0]) return 0;
	for (i=0; i<n; ++i)
	{
		j=(i+1)%n;
		if (x==xp[j] and y==yp[j]) return 0;
		if ( xp[i]==xp[j] )
		{
			if ( x==xp[i] and  y<max(yp[j],yp[i]) and  y>min(yp[j],yp[i]) )
				return 0;
			continue;
		}
		//if ( yp[i]==yp[j] )
		//{
		//	if (   x<xmax(yp[j],xp[i]) and  x>min(xp[j],xp[i]) )
	//			return 0;
	//		continue;
	//	}
		if ( not ( x<=max(xp[j],xp[i]) and  x>=min(xp[j],xp[i])  ) ) continue;
		yg=( yp[i]-yp[j] )*( x -xp[i]) / ( xp[i]-xp[j] )  +  yp[i];
		if (yg==y) return 0;
		if (yg>y)
		{
			if (yg==yp[j] and x==xp[j]) //continue;
			{
				if ( revisa(j, i) )
		 			{
	//	 				cout<<x<<" "<<y<<" algo\n";
		 				++conta;
		 			}
			}
			else if (yg==yp[i] and yg==yp[j]) ++conta;
		 	else if (yg!=yp[i]) ++conta;
		}
	}
	//if (conta%2) cout<<x<<" "<<y<<" chido\n";
	return conta&1;
}


int main()
{
	int t, res, i, b;
	scanf("%d", &t);
	while(t--)
	{
		//cout<<"\ncaso\n";
		scanf("%d %d",&n, &b);
		for (i=0; i<n; ++i)
			scanf("%lf %lf", &xp[i], &yp[i]);
		res=0;
		for (i=0; i<b; ++i)
		{
			scanf("%lf %lf", &x, &y);
			res += dentro();
		}
		printf("%d\n", res);
	}
	return 0;
}