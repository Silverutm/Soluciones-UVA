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

#define x first
#define y second
using namespace std;
typedef pair <double, double> dd;
typedef pair <int, int> ii;
typedef vector < int > vi;
//typedef vector < ii > vii;
typedef long long ll;

pair < dd, ii > intevalosX[505];
dd usuarios[1009];
double xp[505], yp[505] ;
int n, u, res,ind_u, ind_p;

int buscar()
{
	while ( intevalosX[ind_p].f.f > usuarios[ind_u].x )
	{
		--ind_p;
		if (ind_p<0)break;
	}
}

bool in(int a, int b,int  c)
{
	int me=min(b,c), may=max(b,c);
	return a>=me and a<=may;
}

int siguiente(int i, int j)
{
	if (i ==0 and j ==n-1) return 1;
	if (i==n-1 and j==0) return n-2;
	if (i<j) return (i+n-1)%n;
	else return (i+1)%n;
}

int cuantos(int ip)
{
	int par=0, izq, der, i, sig;
	double x=usuarios[ind_u].x, y=usuarios[ind_u].y,yg;
	for (i=0; i<=ip; ++i)
	{
		//yg=( yp[i]-yp[j] )*( x -xp[i]) / ( xp[i]-xp[j] )  +  yp[i];
		if ( intevalosX[i].f.s < usuarios[ind_u].x ) continue;
		
		izq=intevalosX[i].s.f; der=intevalosX[i].s.s;

		if ( intevalosX[i].f.s==intevalosX[i].f.f )
		{
			if (intevalosX[i].f.s==usuarios[ind_u].x)
				if (  in( usuarios[ind_u].y, yp[izq], yp[der] ) )
					return 0;
			continue;
		}
		yg=( yp[izq]-yp[der] )*( x -xp[izq]) / ( xp[izq]-xp[der] )  +  yp[izq];
		if (yg==y) return 0;
		if (yg>y)
		{
			if ( x==xp[izq] )
			{
				sig=siguiente(izq, der);
				while (xp[izq]==xp[sig] ) sig=siguiente(sig, izq);
				if (( xp[der]>x and xp[sig]>x ) or  ( xp[der]<x and xp[sig]<x ))
				{
					//cout<<x<<" izqder "<<xp[der]<<" "<<xp[sig]<<endl;
					continue;
				}
				++par;
			}
			else if ( x==xp[der] ) continue;
			else { ++par;
			//if (x==5)
			//	cout<<x<<" cinco "<<xp[izq]<<" "<<xp[der]<<endl;
			}
		}
	}
	//if (par) cout<<par<<"     "<<x<<" "<<y<<endl;
	return par%2;
}

void resolver()
{
	res=0;
	ind_p=n-1;
	for ( ind_u=u-1; ind_u>=0; --ind_u )
	{
		buscar();
		if (ind_p<0) return ;
		res+= cuantos( ind_p);
	}

	//return res;
}


int main()
{
	int t, i, j;
	double d1, d2;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d",&n, &u);
		//n1=n-1;
		scanf("%lf %lf", &xp[0], &yp[0]);
		d2=xp[0];
		for (i=1; i<n; ++i)
		{
			scanf("%lf %lf", &xp[i], &yp[i]);
			d1=xp[i];
			if (  d1<d2 )
				intevalosX[i]= mk( mk( d1, d2 ) , mk(i, i-1  ) );
			else 
				intevalosX[i]= mk( mk( d2, d1 ) , mk(i-1, i  ) );
			d2=d1;
		}

			d1=xp[0];
			if (  d1<d2 )
				intevalosX[0]= mk( mk( d1, d2 ) , mk(0, n-1  ) );
			else 
				intevalosX[0]= mk( mk( d2, d1 ) , mk(n-1, 0  ) );

		sort(intevalosX, intevalosX+n);

		for (i=0; i<u; ++i)
			scanf("%lf %lf", &usuarios[i].x, &usuarios[i].y);
		sort(usuarios, usuarios+u);

		resolver();

		printf("%d\n", res);
	}
	return 0;
}