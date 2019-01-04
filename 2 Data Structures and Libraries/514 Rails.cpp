#include <iostream>
#include <stack>
using namespace std;
int arreglo[1005];
stack <int> pila;
int main()
{
	int n, i, j;
	while (cin>>n, n)
	{
		; //if (arreglo[0]==0){ cout<<"\n";continue;}
		//pila.clear();
		while ( cin>>arreglo[0], arreglo[0] )
		{
			while (!pila.empty()) pila.pop();
			for (int i = 1; i < n; ++i)
				cin>>arreglo[i];
			//for (int i = 0; i < n; ++i) cout<<arreglo[i]<<" "; cout<<endl;
			j=1;
			for (int i = 0; i < n; ++i)
			{
				if ( !pila.empty() and pila.top()==arreglo[i] )
				{	pila.pop(); --j;}
					
				else
					while ( arreglo[i]!=j and j<=n)
					{
						pila.push(j);
						++j;
					}
				++j;			
			}
			if (pila.empty() ) cout<<"Yes\n";
			else cout<<"No\n";
		}
		cout<<"\n";
	}
	return 0;
}