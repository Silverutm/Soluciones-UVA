#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
using namespace std;
typedef long long ll;
pair <int, int> ii;
vector <int> vi;
string matriz[7] = {"xxxxx ....x xxxxx xxxxx x...x xxxxx xxxxx xxxxx xxxxx xxxxx .....",
					"x...x ....x ....x ....x x...x x.... x.... ....x x...x x...x ..x..",
					"x...x ....x ....x ....x x...x x.... x.... ....x x...x x...x ..x..",
					"x...x ....x xxxxx xxxxx xxxxx xxxxx xxxxx ....x xxxxx xxxxx xxxxx",
					"x...x ....x x.... ....x ....x ....x x...x ....x x...x ....x ..x..",
					"x...x ....x x.... ....x ....x ....x x...x ....x x...x ....x ..x..",
					"xxxxx ....x xxxxx xxxxx ....x xxxxx xxxxx ....x xxxxx xxxxx ....."};

string entrada[7];
bool primer;
bool cosa;
int determinar(int k)
{
	bool valio;
	int i, j;
	for (int numero = 0; numero < 11 ; ++numero)
	{
		valio = false;
		for (i = 0; i < 7 and not valio; ++i)		
			for ( j = 0; j < 5 and not valio; ++j)
			{
				if ( entrada[i][k+j]!=matriz[i][ numero*6 + j] )
					valio=true;
			}		
		if (not valio)
			return numero;
	}
	return 0;
}
bool vez;
int renglon;
void imprimir(int a)
{
	if ( cosa) printf(".");
	for (int j = 0; j < 5; ++j)
	{
		printf("%c",  matriz[renglon][6*a+j]);
	}
	cosa= true;
}

void convertir(int a)
{
	if (not vez and a==0) return;
	

	vez =false;
	convertir(a/10);
	imprimir(a%10);

}

int main()
{
	int numero, a, b, k;
	while ( cin>>entrada[0]>>entrada[1]>>entrada[2]>>entrada[3]
				>>entrada[4]>>entrada[5]>>entrada[6]  )
	{
		primer = true;
		vez = true;
		a = b = 0;
		for (k=0; k<entrada[0].size(); k+=6)
		{
			numero = determinar(k);
			if (numero==10) {primer = false; continue;}
			if (primer)
			{
				a *= 10;
				a += numero;
			}
			else
			{
				b *=10;
				b += numero;
			}
		}
		//cout<<a<<" "<<b<<endl;
		//cout<<a+b<<endl;
		for ( renglon = 0; renglon < 7; ++renglon)
		{
			vez = true;
			cosa=false;
			convertir(a+b);
			printf("\n");
		}
	}
	return 0;
}