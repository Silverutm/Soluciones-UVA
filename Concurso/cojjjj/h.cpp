#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair <int , int> ii;


int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int tam;
		scanf("%d", &tam);
		string cadena_original;
		cin >> cadena_original;
		//scanf("%s", &cadena_original);

		string cadena_ordenada = cadena_original;
		sort(cadena_ordenada.begin(), cadena_ordenada.end());

		vi conta_rep;
		int contador =  1;
		
		for (int i = 1; i < cadena_ordenada.size(); i++)
		{
			if (cadena_ordenada[i-1] ==  cadena_ordenada[i])
			{
				contador++;
			}
			else
			{
				conta_rep.pb(contador);
				contador = 1;
			}
			if (i == cadena_ordenada.size()-1)
			{
				conta_rep.pb(contador);
			}

		}
		if (cadena_ordenada.size()==1)		
			conta_rep.pb(1);		

		bool primero =  true;
		char guarda = '1';
		int k;
		string respuesta1 = "";
		for (int i = 0, j = 0; i < conta_rep.size(); ++i)
		{
			if (conta_rep[i] % 2 == 0)
			{
				k = conta_rep[i] / 2;
				string cad_auxi (cadena_ordenada.begin() + j, cadena_ordenada.begin() + j + k);
				//cout << cad_auxi << endl;
				respuesta1 += cad_auxi;
			}

			else if (conta_rep[i] % 2 != 0 && primero)
			{
				k = conta_rep[i] / 2;
				string cad_auxi (cadena_ordenada.begin() + j, cadena_ordenada.begin() + j + k);
				respuesta1 += cad_auxi;
				primero =  false;
				guarda = cadena_ordenada[j];
			}

			else if (conta_rep[i] % 2 !=0 && !primero)
			{
				k =  conta_rep[i] / 2;
				string cad_auxi (cadena_ordenada.begin() + j, cadena_ordenada.begin() + j + k);
				respuesta1 += cad_auxi;
			}

			j += conta_rep[i];
		}

		string respuesta2;
		for (int i = respuesta1.size()-1; i >= 0; i--)
			respuesta2.pb(respuesta1[i]);
		if (guarda == '1')
			cout << respuesta1 << respuesta2 << endl;
		else
			cout << respuesta1 << guarda << respuesta2 << endl;
	}
	
	return 0;
}