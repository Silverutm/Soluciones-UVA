#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
queue <int> izquierda, derecha, salida;
int c, n, t, m, a;
bool ladoi=true;
int main()
{
	
	string s;
	scanf("%d", &c);
	while (c--)
	{
		total=0;
		izquierda.clear();
		derecha.clear();
		salida.clear();
		scanf("%d %d %d", &n, &t, &m);
		while (m--)
		{
			cin>>a>>s;
			if (s="left") izquierda.push(a);
			else derecha.push(a);
		}
		while ( !izquierda.empty() || !derecha.empty() )
		{
			if ( !izquierda.empty() && !derecha.empty() )
			{
				if ( ladoi )
					while( izquierda.front()<=total )
					{
						salida.push( izquierda.front() );
						izquierda.pop();
					}
				else
					while( derecha.front()<=total )
					{
						salida.push( derecha.front() );
						derecha.pop();
					}
			}
		}


	}
	return 0;
}
