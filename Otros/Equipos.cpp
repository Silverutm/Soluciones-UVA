#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
map <string , int> mapa;
string lugar, nombre, escuela, basura;
struct Lista
{
	string lugar, nombre, escuela;
};
vector <Lista> Oficial;
int main()
{

	while ( getline(cin, lugar) )
	{
		getline(cin, nombre);
		getline(cin, escuela);
		for (int i=0; i<10; ++i)
			getline(cin, basura);
		++mapa[escuela];
		//if (nombre=="twt");
		//else 
			if ( mapa[escuela] > 2 ) continue;
		Oficial.push_back( Lista{lugar, nombre, escuela} );
	}
	for (int i=0; i<Oficial.size(); ++i)
		cout<<Oficial[i].lugar<<" "<<Oficial[i].nombre<<" "
		<<Oficial[i].escuela<<endl;
	return 0;
}