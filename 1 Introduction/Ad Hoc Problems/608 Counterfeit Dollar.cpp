#include <iostream>
#include <vector>
#include <cstring>
#include <cstring>
#include <set>
using namespace std;
int arreglo[15];
#define up 0
#define down 1
#define no -1
string s1, s2,r;
//set <char> sup, sdown;

//set <char> interseccion(set <char> ms1, string s)
//{
//	set <char> de;
//	for (auto e:s)
//		if ()
//}

void f()
{
	cin>>s1>>s2>>r;
	if (r=="even")
	{
		for (auto& e:s1)
			arreglo[e-'A']=no;
		for (auto& e:s2)
			arreglo[e-'A']=no;
	}
	else if (r=="up")
	{
		for (auto& e:s1)
			if (arreglo[e-'A']==0)
				arreglo[e-'A']=down;
			else if (arreglo[e-'A']==up)
				arreglo[e-'A']=no;
		for (auto& e:s2)
			if (arreglo[e-'A']==0)
				arreglo[e-'A']=up;
			else if (arreglo[e-'A']==down)
				arreglo[e-'A']=no;
	}
	else 
	{
		for (auto& e:s2)
			if (arreglo[e-'A']==0)
				arreglo[e-'A']=down;
			else if (arreglo[e-'A']==up)
				arreglo[e-'A']=no;
		for (auto& e:s1)
			if (arreglo[e-'A']==0)
				arreglo[e-'A']=up;
			else if (arreglo[e-'A']==down)
				arreglo[e-'A']=no;
	}
}

int main()
{
	int n;
	
	cin>>n;
	while (n--)
	{
		memset(arreglo, 0, sizeof arreglo);
		//sdown.clear(); sup.clear();
		//for (char i='A'; i<='L'; ++i)
		//{
		//	sdown.insert(i);
		//	sup.insert(i);
		//}
		f(); f(); f();
		vector <int> vu, vdo;
		for (int i=0; i<12; ++i)
			if (arreglo[i]==up) vu.push_back(i);
		else if (arreglo[i]==down) vdo.push_back(i);
		cout<<15-n<<endl;
		if (vu.size()==1)
			printf("%c is the counterfeit coin and it is light.\n", vu[0]+'A');
		if (vdo.size()==1)
			printf("%c is the counterfeit coin and it is light.\n", vdo[0]+'A');

	}
	return 0;
}