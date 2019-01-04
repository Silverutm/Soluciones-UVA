#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
struct equipo
{
	int numero;
	string nombre;
	int puntos, penalizacion;
	int problemas[13], intentos[13], tiempo[13], intentos_parciales[13];
	bool fuera_de[13];
};

int aentero(string s)
{
	int res = 0;
	for (auto e: s)
	{
		res *= 10;
		res += e - '0';
	}
	return res;
}

bool f( equipo a, equipo b )
{ return a.puntos> b.puntos; }

int primero_enresolver[13];

map <string, int> id_equipo;
map <string, int> id_problema;
string trofeo(int j)
{
	if (j<=3)
		return " <i class=\"fa fa-trophy\" aria-hidden=\"true\"></i>";
	return "";
}
int main()
{
	equipo Lista[50];
	
	id_problema["Al revés"]=1;
	id_problema["Binarios Everywhere"]=2;
	id_problema["Cupo Limitado"]=3;
	id_problema["Divide y Vencerás"]=4;
	id_problema["Es lo mismo pero diferente"]=5;
	id_problema["Finding Ekt"]=6;
	id_problema["Galaxias Celulares"]=7;
	id_problema["Hongos Mágicos"]=8;
	id_problema["Inverosímil"]=9;		
	
	int n=0, numero=0, numero_problema, m=9;
	string problema, team, id, lenguaje, tiempo, resultado, escore, estatus, during, ver;
	while ( getline(cin, problema) and
			getline(cin, team) and
			getline(cin, id) and
			getline(cin, lenguaje) and
			getline(cin, tiempo) and
			getline(cin, resultado) and
			getline(cin, escore) and
			getline(cin, estatus) and
			getline(cin, during) and
			getline(cin, ver)
		)
	{
		
		numero=id_equipo[team];
		if ( numero==0 )
		{
			++n;
			numero = n;
			id_equipo[team] = numero;
			Lista[numero].numero=numero;
			Lista[numero].nombre=team;
			for (int i = 0; i < 13; ++i)
			{
				Lista[numero].problemas[i]=0;
				Lista[numero].intentos[i]=0;
				Lista[numero].intentos_parciales[i]=0;
				Lista[numero].tiempo[i]=0;
				Lista[numero].fuera_de[i]=false;
			}
			Lista[numero].puntos=0;
		}
		
		numero_problema=id_problema[problema];		
		if (during=="No" and aentero(escore) )
			Lista[numero].fuera_de[numero_problema] = true;
		++Lista[numero].intentos_parciales[numero_problema];
		if ( aentero(escore) )			
				primero_enresolver[numero_problema] = numero;
		if ( aentero(escore) >  Lista[numero].problemas[numero_problema] )
		{
			Lista[numero].problemas[numero_problema] = 	aentero(escore);
			Lista[numero].tiempo[numero_problema] += aentero(tiempo);
			Lista[numero].intentos[numero_problema] = Lista[numero].intentos_parciales[numero_problema];			
		}		
	}
	//return 0;
	for (int j = 1; j <= n ; ++j)
	for (int i = 1; i <= m ; ++i)
	{
		Lista[j].puntos += Lista[j].problemas[i];
		Lista[j].penalizacion += Lista[j].tiempo[i] + max(0,(Lista[j].intentos[i]-1)*10);
	}
	//for (auto e: id_problema)
	//	cout<<e.first<<" ";
	for (int i = 1; i <= m ; ++i)
		for (auto e: id_problema)
			if (e.second == i)
			{
				cout<<e.first<<" ";
				break;
			}
	cout<<endl;
	sort( Lista+1, Lista+n +1, f);
	for (int j=1; j<= n; ++j)
	{
		//cout<<Lista[j].nombre<<" "<<Lista[j].puntos;
		cout<<"<tr>\n";
		cout<<"<td class='rank'>"<<j<<trofeo(j)<<"</td>\n";
		cout<<"<td >"<<Lista[j].nombre<<"</td>\n";
		cout<<"<td></td>";
		cout<<"<td class='total'>"<<Lista[j].puntos <<"</td>\n";
		//cout<<"<td class='total'>"<<Lista[j].penalizacion <<"</td>\n";
		cout<<"<td class='total'>"<< "--" <<"</td>\n";
		for (int i = 1; i <= m ; ++i)
		{
			if (Lista[j].fuera_de[i])
			{	
				cout<<"<td class=\"group_leader team_problem_cell\">\n";
				cout<<Lista[j].problemas[i]<<"<br />\n";
				//cout<<"<small>"<<Lista[j].tiempo[i] <<"</small>\n";
				cout<<"<small>"<< "--" <<"</small>\n";
			}
			else if (primero_enresolver[i] == Lista[j].numero)
			{	
				cout<<"<td class=\"solvedfirst team_problem_cell\">\n";
				cout<<Lista[j].problemas[i]<<"<br />\n";
				//cout<<"<small>"<<Lista[j].tiempo[i] <<"</small>\n";
				cout<<"<small>"<< "--" <<"</small>\n";
			}
			else if ( Lista[j].problemas[i] )
			{	
				cout<<"<td class=\"solved team_problem_cell\">\n";
				cout<<Lista[j].problemas[i]<<"<br />\n";
				//cout<<"<small>"<<Lista[j].tiempo[i] <<"</small>\n";
				cout<<"<small>"<< "--" <<"</small>\n";
			}
			else if (Lista[j].intentos_parciales[i] )
			{
				cout<<"<td class=\"attempted team_problem_cell\">";
				cout<<Lista[j].problemas[i]<<"<br />\n";
				//cout<<"<small>"<<Lista[j].tiempo[i] <<"</small>\n";				
				cout<<"<small>"<< "--" <<"</small>\n";
			}
			else cout<<"<td>";
			cout<<"</td>\n";			
		}		
		cout<<"</tr>\n";
	}
	return 0;
}