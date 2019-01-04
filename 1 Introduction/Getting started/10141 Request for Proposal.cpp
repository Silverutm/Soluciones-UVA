#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	string s, marca;
	//vector <string> marcas;
	//vector < pair <double, int> > minimo_precio;
	int maxi_reque, reque, caso=0;
	double precio, marca_precio;
	while(cin>>m>>n and (n or m))
	{
		if (caso) cout<<"\n";
		++caso;
		getline(cin, s);
		while (m--) getline(cin, s);
		//marcas.clear();
		maxi_reque=0;
		while (n--)
		{
			getline(cin, s);
			//marcas.push_back(s);
			cin>>precio>>reque;			
			if (reque>maxi_reque)
			{
				marca=s;
				marca_precio=precio;
				maxi_reque=reque;	
			}
			else if (reque==maxi_reque)
				if (precio<marca_precio)
				{
					marca=s;
					marca_precio=precio;	
				}	
			getline(cin, s);
			while (reque--) getline(cin, s);
		}
		cout<<"RFP #"<<caso<<"\n"<<marca<<endl;

	}	
	return 0;
}