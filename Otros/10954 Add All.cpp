#include <queue>
#include <iostream>
using namespace std;
int main()
{
	int a, b, n, suma;
	//de menor a mayor
	priority_queue <int, vector<int>,greater<int> > coladeprioridad;
	while (cin>>n and n)
	{
		suma=0;
		while (n--)
		{
			cin>>a;
			coladeprioridad.push(a);			
		}
		while(coladeprioridad.size()>1 )
		{
			a=coladeprioridad.top();
			coladeprioridad.pop();
			b=coladeprioridad.top();
			coladeprioridad.pop();
			coladeprioridad.push(a+b);
			suma += a+b;
		}
		cout<<suma<<endl;
		coladeprioridad.pop();
	}
	return 0;
}