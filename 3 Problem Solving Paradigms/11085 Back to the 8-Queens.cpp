#include <iostream>
#include <vector>
#include <cstdio>
#include <bitset>
using namespace std;
int cuantos, parcial;
bitset <20> rows, d1, d2;
vector <int> sol(10), v(10);
vector <vector <int>> Lista;

void buscar(int c)
{
	if (c==9 )
		Lista.push_back(sol);
	else
	for (int i=1; i<=8; ++i)
	{
		//si la diagonal fila, y diagonales donde
		//quiero poner a la reina esta desocupado
		if ( !rows[i] and !d1[i+c] and !d2[i-c+8] )
		{
			//las ocupo
			rows[i] = d1[i+c] = d2[i-c+8]=true;
			sol[c]=i; //lo pongo en la posible solucion
			
			buscar(c+1);	//me paso a la siguiente columna
			
			//la desocupo para intentar poner otra reina en
			//la misma columna
			rows[i] = d1[i+c] = d2[i-c+8]=false;	
		}
	}
	return ;
}

void contar()
{
	for (int i = 1; i < 9; ++i)
		if (sol[i]!=v[i])
			++parcial;
}

int main()
{
	buscar(1);
	int caso=0;
	while (cin>>v[1])
	{
		d1.reset();
		d2.reset();
		rows.reset();

		for (int i = 2; i <= 8; ++i)
			cin>>v[i];		
		cuantos = 8;
		for (auto s:Lista)
		{
			sol = s;
			parcial = 0;
			contar();
			cuantos = min(cuantos, parcial);
		}
		cout<<"Case "<<++caso<<": ";
		cout<<cuantos<<"\n";
	}
	return 0;
}