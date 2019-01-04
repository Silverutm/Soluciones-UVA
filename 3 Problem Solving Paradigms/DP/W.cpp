
	#include <iostream>
	#include <algorithm>
	#include <cstring>
	#include <vector>
	#define pb push_back
	#define inf 1000000
	using namespace std;

	typedef vector <int> vi;

	vector < vi > tabla;
	int rd[21][201];
int k; 
	int gastado(int n, int d)
	{
		//cout<<n<<" "<<d<<endl;
		int res;
		if(d<0){
			//cout<<d<<" < "<<0<<" return -inf"<<endl;
			return -inf;
		}
		if(n==k) {
			//cout<<n<<" = "<<tabla.size()<<endl;
			return rd[n][d]=0;
		}
		if(rd[n][d]!=-1){
			//cout<<"rd["<<n<<"]["<<d<<"]"<<" = "<< rd[n][d]<<endl;
			return rd[n][d];
		}
		else
		{
			res=-inf;
			for(auto c: tabla[n])
				res=max(res, gastado(n+1,d-c)+c);
		//	cout<<"res = "<<res<<endl;
			rd[n][d]=res;
			return res;
		}
	}

void p1()
{
	for (auto v: tabla)
	{
		for(auto c: v)
			cout<<c<<" ";
		cout<<endl;
	}
}

void p2()
{
	for (int i=0; i<k; ++i)
	{
		for (int j=0; j<=20; ++j)
		{
			cout<<rd[i][j]<<" ";
		}
		cout<<endl;
	}
}


	int main(int argc, char const *argv[])
	{
		//Número de niveles
		int dinero; //Total de dinero
		int r; // Tipos por cada nivel
		int c;
		int N;
		cin>>N;

		while (N--)
		{
			memset (rd,-1, sizeof rd);
			tabla.clear();
			cin>>dinero>>k;
			tabla.resize(k+1);
			for (int i=0; i<k; i++)
			{
				cin>>r;
				for(int j=0; j<r; j++)
				{
					cin>>c;
					tabla[i].pb(c);
				}
			}
			int pp=gastado(0,dinero);
			if(pp<0)
				cout<<"no solution"<<endl;
			else 
				cout<<pp<<endl;
			p2();
			
		}
		return 0;
	}