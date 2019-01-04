#include <iostream>
#include <cctype>
using namespace std;
struct m
{
	int y, x;
	bool usado;
};
int i, j, k;
m matriz[500];
char cosa [6][6];
void siguiente()
{
	++j;
	if (j==5)
	{
		++i; j=0;
	}
}

bool ft=true;
void imprimir(char f1, char f2)
{
	//if (f2>f1)
	//{
		cout<<(char)toupper( f1 ) <<(char)toupper( f2 );
	//	ft=false;
	//}
	//else cout<<(char)toupper( f1 )<<(char)toupper( f2 );
}

void magia(char f1, char f2)
{
	if ( f1== f2 )
	{
		magia(f1, 'x');
		//cout<<f1<<'x';
		--k;
	}

	else if ( matriz[ f1 ].y == matriz[ f2 ].y )
	{
		imprimir( cosa[ matriz[ f1 ].y ][ (matriz[ f1 ].x + 1)%5 ], 
			cosa[ matriz[ f1 ].y ][ (matriz[ f2 ].x + 1)%5 ] );
		//cout<<(char)toupper(  )
		//	<<(char)toupper(  );
	}

	else if ( matriz[ f1 ].x == matriz[ f2 ].x )
	{
		imprimir (  cosa[ (matriz[ f1 ].y + 1)%5 ][ matriz[ f1 ].x ], 
			cosa[ (matriz[ f2 ].y + 1)%5 ][ matriz[ f1 ].x ] );
		//cout<<(char)toupper(  )
		//	<<(char)toupper(  );
	}

	else
	{
		imprimir( cosa[ matriz[ f1 ].y ][ matriz[ f2 ].x ],
			cosa[ matriz[ f2 ].y ][ matriz[ f1 ].x ] );
		//cout<<(char)toupper(  )
		//	<<(char)toupper(  );
	}
}

int main()
{
	int t;
	string llave, frase;
	cin>>t;
	getline(cin, llave);
	while ( t-- )
	{
		ft=true;
		getline(cin, llave);
		getline(cin, frase);
		i = j = 0;
		for (int e = 'a'; e <= 'z'; ++e)
			matriz[e].usado = false;
		//cout<<llave<<endl;
		//cout<<frase<<endl;
		for (auto e: llave)
		{
			if ( e!= ' ' )
			if ( !matriz[e].usado )
			{
				matriz[e].usado = true;
				matriz[e].y = i;
				matriz[e].x = j;
				cosa[i][j] = e;
				siguiente();
			}
		}
		for (int e = 'a'; e <= 'z'; ++e)
		{
			if ( e!='q' )
			if ( !matriz[e].usado )
			{
				matriz[e].usado = true;
				matriz[e].y = i;
				matriz[e].x = j;
				cosa[i][j] = e;
				siguiente();
			}
		}

		for ( k = 0; k < frase.size(); )
		{
			if ( frase[k]==' ' ) {++k;continue;}
			
			if ( k==frase.size()-1 )
			{
				magia(frase[k], 'x');
				break;
			}				

			else
			{
				char f1, f2;
				f1 = frase[k];
				int w=1; while ( frase[k+w]==' ' ) ++w;
				f2= frase[k+w];
				magia( f1 , f2 );
				k = k+ w+1;
			}
		}
		cout<<endl;
		/*for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				cout<<cosa[i][j];
			}
			cout<<endl;
		}*/
	}
	return 0;
}