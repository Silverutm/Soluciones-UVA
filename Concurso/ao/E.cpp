#include <iostream>
#include <queue>
using namespace std;
int l;
queue <int> izq, der;
bool siniestra=true;

int resolver()
{
	//cout<<endl;
	int r=0, carga;
	while (!izq.empty() or !der.empty() )
	{		
		carga=0;
		if (siniestra)
		{
			while ( !izq.empty() and carga+izq.front()<=l )
			{
				carga+=izq.front();
				izq.pop();
			}
			if ( carga or !der.empty() )
			{
				++r;
				siniestra=not siniestra;
				//cout<<carga<<" izq"<<endl;
			}
		}
		else
		{
			while ( !der.empty() and carga+der.front()<=l )
			{
				carga+=der.front();
				der.pop();
			}
			if ( carga or !izq.empty() )
			{
				++r;
				siniestra=not siniestra;
				//cout<<carga<<" der"<<endl;
			}
		}
	}
	return r;
}

int main()
{
	string s;
	int t, a, m;
	cin>>t;
	while (t--)
	{
		cin>>l>>m;
		l *= 100;
		siniestra=true;
		while (m--)
		{
			cin>>a>>s;
			if (s=="left") izq.push(a);
			else der.push(a);
		}
		cout<<resolver()<<endl;
	}
	return 0;
}