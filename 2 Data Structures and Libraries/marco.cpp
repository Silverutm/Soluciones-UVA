#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

bool f( pair<vector<int>, int> a, pair<vector<int>, int> b)
{
	return a.second > b.second;
}

int main()
{
	int n;
	map <vector <int>,int> alumnos;
	vector <int> bloque(5);
	while (cin>>n and n!=0)
	{
		alumnos.clear();
		cout<<"\n\n\n";
		for (int i=0;i<n;i++)
		{
			
			for (int j=0;j<5;j++)
			{
				//int a;
				cin>>bloque[j];
				//bloque.push_back(a);
			}
			sort (bloque.begin(),bloque.end());
			++alumnos[bloque];
			//cout<<alumnos[bloque]<<"."<<endl;
		}
		int x=0;
		//int m=(*max_element(alumnos.begin(),alumnos.end(), f)).second;
		for (auto e:alumnos)
		{
			//for (auto a:e.first)
			//	cout<<a<<" ";
			//cout<<endl;
			if (e.second==m)
				x++;
		}
		//cout<<m<<" "<<x<<endl;
		m*=x;
		cout<<m<<endl;
	}
}