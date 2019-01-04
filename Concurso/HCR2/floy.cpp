#include <bits/stdc++.h>
#define s second
#define f first
#define mk make_pair
#define pb push_back
#define tam 305
#define INF 100000000LL
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;

ll mod =1000000007LL;

ll p[tam][tam], AdjMat[tam][tam];
int V, m, a,b,c;
int popo;
void imprimir()
{
	cout<<"Con los primeros $"<<popo++<<"$ vertices como intermediarios de $i,j$"<<endl;
	cout<<"$$M=\\begin{blockarray}{ccccc}"<<endl;
	cout<<"& v_1 & v_2 & v_3 & v_4 \\\\"<<endl;
	cout<<"\\begin{block}{c[cccc]}"<<endl;
	for (int i = 0; i < V; i++)
	{
		cout<<"v_"<< i+1 <<"\\text{ } ";
		for (int j = 0; j < V; j++) // this time, we need to use if statement
		{
			if (AdjMat[i][j]==INF)
				cout<<"& \\infty ";
			else cout<<"& "<<AdjMat[i][j]<<" ";
		}
		cout<<"\\\\"<<endl;
	}
	cout<<"\\end{block}"<<endl;
	cout<<"\\end{blockarray} \\quad \\quad"<<endl;
	cout<<"P=\\begin{blockarray}{ccccc}"<<endl;
	cout<<"& v_1 & v_2 & v_3 & v_4 \\\\"<<endl;
	cout<<"\\begin{block}{c[cccc]}"<<endl;
	for (int i = 0; i < V; i++)
	{
		cout<<"v_"<< i+1 <<"\\text{ } ";
		for (int j = 0; j < V; j++) // this time, we need to use if statement
		{
			
			cout<<"& "<<p[i][j]+1<<" ";
		}
		cout<<"\\\\"<<endl;
	}
	cout<<"\\end{block}"<<endl;
	cout<<"\\end{blockarray}$$"<<endl;
	cout<<endl;
}


int main()
{
	
	cin>>V>>m;

	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
			AdjMat[i][j] = INF;	

	for (int i = 0; i < V; i++)
		AdjMat[i][i]=0;
	while (m--)
	{
		cin>>a>>b>>c;
		--a; --b;
		AdjMat[b][a]=AdjMat[a][b]=c;
	}

	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
			p[i][j] = i; // initialize the parent matrix
	imprimir();
	for (int k = 0; k < V; k++)
	{
		for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++) // this time, we need to use if statement
		if (AdjMat[i][k] + AdjMat[k][j] < AdjMat[i][j]) 
		{
			AdjMat[i][j] = AdjMat[i][k] + AdjMat[k][j];
			p[i][j] = p[k][j]; // update the parent matrix
		}
		imprimir();
	}
	return 0;
}


