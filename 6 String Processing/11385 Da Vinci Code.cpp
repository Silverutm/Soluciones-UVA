#include <iostream>
#include <map>
#include <cctype>
using namespace std;
int fibo[105];
int main()
{
	fibo[1]=1;
	fibo[2]=2;
	for (int i = 3; fibo[i-1] < 1836311903; ++i)
	{
		fibo[i] = fibo[i-1] + fibo[i-2];
	}
	map <int, int> mapa;
	for (int i = 1; fibo[i-1] < 1836311903; ++i)
	{
		mapa[ fibo[i] ] = i;
	}
	//string s;
	//s.resize(10, ' ');
	//cout<<s<<endl;
	int t, n, arreglo[100];
	pair <int, char> salida[1000];
	cin>>t;
	string s1, s2, s3;
	while ( t-- )
	{
		cin>>n;
		for (int i=0; i<n; ++i)
			cin>>arreglo[i];
		getline(cin, s1);
		getline(cin, s1);
		s2.clear();
		for (auto e:s1)
			if (e>='A' and e<='Z' )
				s2.push_back(e);
		s3.clear();
		s3.resize(1000, ' ');
		for (int i = 0; i < n; ++i)
		{
			s3[ mapa[ arreglo[i] ] ] = s2[i];
			//salida[ mapa[ arreglo[i] ] ].second = s2[i];
		}
		//cout<<s2<<endl;
		//return 0;
		int j=0;
		for (int i=1; j<n; ++i)
		{
			if ( s3[i]!= ' ' )
			{
				cout<<s3[i];
				++j;
			}
			else cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}