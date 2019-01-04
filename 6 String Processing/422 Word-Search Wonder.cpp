#include <iostream>
#include <cstdlib>
using namespace std;
string matriz[115];
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

bool kmpSearch(int y, int x, int yi, int xi, int yf, int xf, bool ym, bool xm)
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
			cout<<res.first+1<<","<<res.second+1<<" ";
			cout<<y-yi+1<<","<<x-xi+1<<endl;
			return true;
		} 
	}
	return false;
}

int main()
{
	int t, p;
	
	cin>>f; c=f;
	for (int i = 0; i < f; ++i)
		cin>>matriz[i];
	bool posible = false;
	while (cin>>P and P!="0")
	{
		
		m=P.size();
		posible=false;
		
		res=make_pair(f+5, c+5);
		kmpPreprocess();
		for (int i = 0; i < f; ++i)
		{
			posible = posible or kmpSearch(i, 0, 0, 1, i+1, c, true, true);
			posible = posible or kmpSearch(i, 0, 1, 1, f, c, true, true);
			posible = posible or kmpSearch(i, 0, -1, 1, -1, c, false, true);

			posible = posible or kmpSearch(i, c-1, 0, -1, i+1, -1, true, false);
			posible = posible or kmpSearch(i, c-1, 1, -1, f, -1, true, false);
			posible = posible or kmpSearch(i, c-1, -1, -1, -1, -1, false, false);
		}

		for (int i = 0; i < c; ++i)
		{
			//cout<<i<<" aqui hay algo extrano\n";
			posible = posible or kmpSearch(0, i, 1, 0, f, i+1, true, true);
			posible = posible or kmpSearch(0, i, 1, 1, f, c, true, true);
			posible = posible or kmpSearch(0, i, 1, -1, f, -1, true, false);

			posible = posible or kmpSearch(f-1, i, -1, 0, -1, i+1, false, true);
			posible = posible or kmpSearch(f-1, i, -1, 1, -1, c, false, true);
			posible = posible or kmpSearch(f-1, i, -1, -1, -1, -1, false, false);
		}
		
		if (not posible) cout<<"Not found\n";
		
		
	}
	//if (t) cout<<"\n";
	
	return 0;
}