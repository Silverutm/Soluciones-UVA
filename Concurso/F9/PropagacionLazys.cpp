#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define For(x,a,b) for(int x=a; x<b; x++)
#define inf 1<<29
using namespace std;


typedef vector <int> vi;

int izq(int a){return (a<<1)+1;}
int der(int a){return (a<<1)+2;}

vi arr,lazy,st;

void inicia(int i,int j,int nodo)
{
	if(i == j)
	{
		st[nodo] = 	arr[i];
		return;
	}
	
	int m = (i+j)>>1;
	
	inicia(i,m,izq(nodo));
	inicia(m+1,j,der(nodo));
	
	st[nodo] = min(st[izq(nodo)], st[der(nodo)]);
}

void act(int i,int j,int a,int b,int nodo,int val)
{
	if(lazy[nodo] != 0)
	{
		st[nodo] += lazy[nodo];
		
		if(i != j)
		{
			lazy[izq(nodo)] += lazy[nodo];
			lazy[der(nodo)] += lazy[nodo];
		}
		
		lazy[nodo] = 0;
	}
	
	int m = (i+j)>>1;
	
	if(i > b || i > j || j < a) return ;
	
	if(i == a && j == b)
	{
		st[nodo] += val;
		
		if(i != j)
		{
			lazy[izq(nodo)] += val;
			lazy[der(nodo)] += val;
		}
		return;
	}
	if(b <= m)
	{
		act(i,m,a,b,izq(nodo),val);
	}
	else if(a > m)
	{
		act(m+1,j,a,b,der(nodo),val);
	}
	else
	{
		act(i,m,a,m,izq(nodo),val);
		act(m+1,j,m+1,b,der(nodo),val);
		
		st[nodo] = min(st[izq(nodo)],st[der(nodo)]);
	}
	
	
}

int query(int i,int j,int a,int b,int nodo)
{
	if(lazy[nodo] != 0)//Propagacion
	{
		st[nodo] += lazy[nodo];//Actualizamos este vertice
		
		if(i != j)
		{
			lazy[izq(nodo)] += lazy[nodo];//Lo propagamos a los hijos
			lazy[der(nodo)] += lazy[nodo];
		}
		
		lazy[nodo] = 0;//Reseteamos el papa
	}
	
	if(i == a && j == b)
	{
		return st[nodo];
	}
	
	int m = (i+j)>>1;
	
	if(b <= m)
	{
		return query(i,m,a,b,izq(nodo));
	}
	else if(a > m)
	{
		return query(m+1,j,a,b,der(nodo));
	}
	else
	{
		int r1 = query(i,m,a,m,izq(nodo));
		int r2 = query(m+1,j,m+1,b,der(nodo));
		
		return min(r1,r2); 
	}
}
int main()
{
	int N,c,a,b,k,v,res;
	
	scanf("%d",&N);
	
	st.assign(4*N,0);
	arr.assign(N,0);
	lazy.assign(4*N,0);
	
	For(i,0,N)
	{
		scanf("%d",&arr[i]);
	}
	
	inicia(0,N-1,0);
	
	scanf("%d",&c);
	For(i,0,c)
	{
		scanf("%d",&k);
		if(k)
		{
			scanf("%d %d",&a,&b);
			a--; b--;
			
			res = query(0,N-1,a,b,0);
			printf("%d\n",res);
		}
		else
		{
			scanf("%d %d %d",&a,&b,&v);
			a--; b--;
			
			act(0,N-1,a,b,0,v);
		}
	}
	return 0;
}
