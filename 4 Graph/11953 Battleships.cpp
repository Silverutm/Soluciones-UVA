#include <bits/stdc++.h>
using namespace std;
#define tam 105

string tablero[tam];
int n;
bool tiene_x;

bool dentro(int z)
{
	return z>=0 and z<n;
}

void buscar(int y, int x)
{
	if ( not dentro(y) or not dentro(x)) return;
	if (tablero[y][x]=='.') return;

	if (tablero[y][x]=='x')
		tiene_x= true;
	tablero[y][x] = '.';
	buscar(y-1,x);buscar(y+1,x); buscar(y,x-1); buscar(y,x+1);
}

int main()
{
	int t, vivos;
	cin>>t;
	for (int caso = 1; caso <= t; ++caso)
	{
		cin>>n;
		for (int i = 0; i < n; ++i)
			cin>>tablero[i];

		vivos = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (tablero[i][j]!='.')
				{
					tiene_x = false;
					buscar(i, j);
					if (tiene_x)
						++vivos;
				}
		cout<<"Case "<<caso<<": "<<vivos<<"\n";
	}
	return 0;
}

bool ver_renglon(int renglon)
{
	bitset <9> repetido; //#include <bitset>
	for (int col = 0; col < 9; ++col)
	{
		if (bitset[ board[renglon][col] ] )
			return false; //ya esta repetido
		bitset[ board[renglon][col] ] = true;
	}
}



sugerencias()
{
	char fila, columna;
	cin>>fila>>columna;
	//B2 por ejemplo
	//tu verificas que este dentro de los rangos

	fila = fila - 'A'; //convertir a entero
	columna = columna - '0'; //idem

	set<int> posibles({1,2,3,4,5,6,7,8,9}); //para que uses binary search xD
	//#include <set>
	//si no funciona, usa
	//for (int i = 1; i <= 9; ++i)
	//	posibles.insert(i);

	//eliminar ya elegidos en la columna
	for (int col = 0; col < 9; ++col)
	{
		int n =board[fila][col] ];
		
		if (posibles.find(n)!= posibles.end())
			posibles.erase(n);
	}

	//eliminar ya elegidos en la fila
	for (int reng = 0; reng < 9; ++reng)
	{
		int n =board[reng][columna] ];
		
		if (posibles.find(n)!= posibles.end())
			posibles.erase(n);
	}

	//ahora debemos obtener el cuadrado al que pertenece
	int num_fila = fila/3;
	int num_columna = columna/3;
	//listo

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
		{
			int n= board[ num_fila*3 +i ][ num_columna*3 +i ];
			if (posibles.find(n)!= posibles.end())
			posibles.erase(n);
		}

	for (auto &e: posibles)
		cout<<e<<" ";
	cout<<endl;
}