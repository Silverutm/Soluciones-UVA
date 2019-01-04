#include <bits/stdc++.h>
using namespace std;
int arreglo[500];
int main()
{
	int n, t;
	cin>>n;
	string s;
	bool b;
	while (n--)
	{
		cin>>s;
		b= false;
		t=0;
		memset(arreglo, 0, sizeof arreglo);
		for (auto& e: s)
			++arreglo[e];
		for (int i='A'; i<='Z'; ++i)
		{
			if (arreglo[i]%2)
			{
				if (b) --arreglo[i];
				b=true;
			}
			t+=arreglo[i];
		}
		cout<<t<<endl;
	}
	return 0;
}