#include <iostream>
#include <vector>
#define pb push_back
using namespace std;
typedef vector <int> vi;
int n, t;
vi entrada, sol, posible;
int suma, parcial;
void genera(int k)
{
	if (parcial>n) return;
	if (parcial>suma)
		{
			suma=parcial;
			sol=posible;			
		}
	if (k==t)
	{
		
		return ;
	}

	for (int i=k; i<t; ++i)
	{
		posible.pb( entrada[i] );
		parcial+=entrada[i];
		genera(i+1);
		posible.pop_back();
		parcial-=entrada[i];
	}
	return ;
}

int main()
{
	int a, i;
	while (cin>>n>>t)
	{
		entrada.clear();
		for (i=0; i<t; ++i)
		{
			cin>>a;
			entrada.pb(a);
		}
		suma=0;
		parcial=0;
		posible.clear();
		genera(0);
		for (auto e: sol)
			cout<<e<<" ";
		cout<<"sum:"<<suma<<endl;
	}
	return 0;
}