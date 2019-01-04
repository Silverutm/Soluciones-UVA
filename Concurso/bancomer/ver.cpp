#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	string s;
	int n=497184, cont=0;
	while (getline(cin, s))
		++cont;
		//cout<<s<<"\n";
	cout<<cont<<endl;
	
	return 0;
}


//dar algoritmo que tuvo mas referencias erroneas
//tantas erroneas
//mostrar porcentaje de erroneas

//porcentaje de referencias erroneas
//creatividad, uso de herramientas
//tiempo de respuestas
//escalabilidad
//sentido del humor


//
//AKRs_91_k4_m
/*
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	string s;
	while (getline(cin, s))
	{
		for (auto &c:s)
			if (c=='|') printf("%c", ',');
			else printf("%c", c);
		printf(",\n");

	}
}*/