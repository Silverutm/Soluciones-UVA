#include <string>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <bitset>
using namespace std;
long long res, temp;
long long modulo, respuestas[1000009];

void modular(int n)
{
	//res	+= (1<<(i-1))*i;
	/*temp=1;
	for (int i=1;i<=n; ++i)
	{
		temp <<= 1;
		temp %=modulo;
		temp=respuestas
	}
	temp *=n+1;
	temp %=modulo;*/
	//res+=temp;
	temp+= respuestas[n];
	temp *=n+1;
	temp %=modulo;
	res+=temp;
	res %=modulo;
}

int main()
{
	string s;
	int i;
	long long parcial=0;
	cin>>s>>modulo;
	//memset(respuestas, -1, sizeof respuestas);
	s.pop_back();
	bitset <1000009> minumero(s);
	//cout<<s<<endl<<minumero<<endl;
	respuestas[0]=1;
	for (i=1; i<s.size(); ++i)
	{
		respuestas[i] = respuestas[i-1]<<1;
		respuestas[i] %= modulo;
		//respuestas[i] *= i+1;
		//respuestas[i] %= modulo;
	}

	//for (i=0; i<s.size(); ++i)
	//	if (minumero[i]) ++parcial;
	res= 0;
	
	//cout<<res<<endl;
	for (i=1; i<s.size(); ++i)
		if (minumero[i])
		{
			temp= respuestas[i-1];
			temp *=i;
			temp %=modulo;
			//cout<<temp<<"  "<<i<<endl;
			res+=temp;
			res %=modulo;			
			//modular(i-1);
		}
	int contador=0;
	long long multi;
	for (i=s.size()-1; i>=0; --i)
	{
		if (minumero[i])
		{
			multi=respuestas[i]*contador;
			multi %=modulo;
			res+=multi;
			res%=modulo;
			++contador;
		}		
	}
	res+=contador;
	//res+=(parcial*(parcial+1))/2;
	res %=modulo;
	//res%=modulo;
	cout<<res<<endl;
	return 0;
}