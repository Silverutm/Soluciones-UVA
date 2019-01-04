#include <bits/stdc++.h>
using namespace std;
#define ini 0
#define fin 1

int grafo[102][102],memo[5002][5002][102],k[5002][2],P;
bool vis[102];

void limpiar(int N) {
	for(int i=1;i<=N;i++)
		for(int l=1;l<=N;l++) 
			if(l!=i)
				grafo[i][l]=1001;
	for(int i=0;i<=P;i++)
		for(int l=0;l<=P;l++)
			for(int j=1;j<=N;j++)
				memo[i][l][j]=0;
	for(int i=1;i<=N;i++)
		vis[i]=0;
}

void Floyd_Warshall(int N) {
	for(int q=1;q<=N;q++)
		for(int i=1;i<=N;i++)
			for(int l=1;l<=N;l++)
				grafo[i][l]=min(grafo[i][q]+grafo[q][l],grafo[i][l]);
}

int dp(int a,int b,int c) {
	if(b==P) 
		return 0;
	if(memo[a][b][c]) 
		return memo[a][b][c];
	int x=INT_MAX;
	int y=INT_MAX;
	if(a>b) //entregar
		x=dp(a,b+1,k[b+1][fin])+grafo[k[b+1][fin]][c];
	if(a-b<2) //recoger
		y=dp(a+1,b,k[a+1][ini])+grafo[k[a+1][ini]][c];
	memo[a][b][c]=min(x,y);
	return memo[a][b][c];
}

int main() {
	int N,M,T,a,b,c;
	bool bandera;
	cin>>T;
	for(int t=1;t<=T;t++) {
		bandera=0;
		cout<<"Case #"<<t<<": ";
		cin>>N>>M>>P;
		limpiar(N);
		for(int i=0;i<M;i++) {
			cin>>a>>b>>c;
			vis[a]=1; vis[b]=1;
			grafo[a][b]=c;
			grafo[b][a]=c;
		}
		Floyd_Warshall(N);
		for(int i=1;i<=P;i++) {
			cin>>k[i][ini]>>k[i][fin];
			if(!vis[k[i][ini]]) bandera=1;
			if(!vis[k[i][fin]]) bandera=1;
		}
		if(bandera)
			cout<<-1<<"\n";
		else
			cout<<dp(0,0,1)<<"\n";
	}
	return 0;
}
