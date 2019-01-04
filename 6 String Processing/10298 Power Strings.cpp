#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector <int> divi;
int main()
{
	string s, parcial;
	int n, limite;
	while (getline (cin, s) and s!=".")
	{
		//cout<<s<<endl;
		n=s.size();
		divi.clear();
		limite = sqrt(n);
		for (int i = 1; i <= limite; ++i)
			if (n%i == 0)
			{
				divi.push_back(i);
				if ( i!=n/i ) divi.push_back(n/i);
			}
		sort(divi.begin(),divi.end());
		parcial.clear();
		//cout<<s<<endl;
		//int w=0;
		for (auto e: divi)
		{
			while ( parcial.size()<e )
				parcial.push_back( s[ parcial.size() ] );
			bool posible=true;
			//cout<<++w<<endl;
			for (int i = parcial.size(); i < s.size() and posible; i+=e)			
				for (int j = i, k=0; k<e and posible; ++k, ++j)				
					if (parcial[k]!= s[j]) posible=false;
			if (posible) {cout<<n/e<<endl;break;}
		}
		//cout<<s<<endl;
	}
	return 0;
}