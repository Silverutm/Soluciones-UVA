#include <iostream>
#include <cstdlib>
using namespace std;
string matriz[100];
int f, c;
string P;
int b[500], m, n;
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
pair <int, int> res;
bool ver(int i, int fi, bool mi)
{
	if (mi) return i<fi;
	return i>fi;
}

void kmpSearch(int y, int x, int yi, int xi, int yf, int xf, bool ym, bool xm)
{ 
	int i = 0, j = 0; 
	while (ver(y, yf, ym) and ver(x, xf, xm)) 
	{ 
		//if (P=="betty")
		//cout<<matriz[y][x] <<" "<< P[j]<<endl;
		while (j >= 0 && matriz[y][x] != P[j]) j = b[j];
		j++;
		//cout<<j<<endl;
		y += yi;
		x += xi;
		
		if (j == m) 
		{ 
			//printf("P is found at index %d in T\n", i - j);
			//cout<<"Encontrado "<<P<<endl;
			auto e= res;
			if (xi<0) res.second=x+j;
			else if (xi>0) res.second= x-j;
			else res.second=x;

			if (yi<0) res.first=y+j;
			else if (yi>0) res.first= y-j;
			else res.first=y;
			//cout<<"aqui"<<P<<endl;
			res = min(res, e  );
			j = b[j]; 
		} 
	}
}

int main()
{
	int t, p;
	cin>>t;
	while (t--)
	{
		cin>>f>>c;
		for (int i = 0; i < f; ++i)
			cin>>matriz[i];

		for (int i = 0; i < f; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				matriz[i][j]=tolower(matriz[i][j]);
				//cout<<matriz[i][j];
			}
			//cout<<endl;
		}
		cin>>p;
		while (p--)
		{
			cin>>P;
			m=P.size();
			for (int i = 0; i < m; ++i)
			{
				P[i]= tolower(P[i]);
				//cout<<P[i];
			}
			//cout<<endl;
			res=make_pair(f+5, c+5);
			kmpPreprocess();
			for (int i = 0; i < f; ++i)
			{
				kmpSearch(i, 0, 0, 1, i+1, c, true, true);
				kmpSearch(i, 0, 1, 1, f, c, true, true);
				kmpSearch(i, 0, -1, 1, -1, c, false, true);

				kmpSearch(i, c-1, 0, -1, i+1, -1, true, false);
				kmpSearch(i, c-1, 1, -1, f, -1, true, false);
				kmpSearch(i, c-1, -1, -1, -1, -1, false, false);
			}

			for (int i = 0; i < c; ++i)
			{
				//cout<<i<<" aqui hay algo extrano\n";
				kmpSearch(0, i, 1, 0, f, i+1, true, true);
				kmpSearch(0, i, 1, 1, f, c, true, true);
				kmpSearch(0, i, 1, -1, f, -1, true, false);

				kmpSearch(f-1, i, -1, 0, -1, i+1, false, true);
				kmpSearch(f-1, i, -1, 1, -1, c, false, true);
				kmpSearch(f-1, i, -1, -1, -1, -1, false, false);
			}
			
			cout<<res.first+1<<" "<<res.second+1<<"\n";
			
			
		}
		if (t) cout<<"\n";
	}
	return 0;
}