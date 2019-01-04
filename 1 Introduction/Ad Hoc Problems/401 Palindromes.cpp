#include <iostream>
using namespace std;
char arreglo[300];
int main()
{
	arreglo['A']='A';
	arreglo['E']='3';
	arreglo['H']='H';
	arreglo['I']='I';
	arreglo['J']='L';
	arreglo['L']='J';
	arreglo['M']='M';
	arreglo['O']='O';
	arreglo['S']='2';
	arreglo['T']='T';
	arreglo['U']='U';
	arreglo['V']='V';
	arreglo['W']='W';
	arreglo['X']='X';
	arreglo['Y']='Y';
	arreglo['Z']='5';
	arreglo['1']='1';
	arreglo['2']='S';
	arreglo['3']='E';
	arreglo['5']='Z';
	arreglo['8']='8';
	string s;
	bool palidromo, espejo;
	int i, j;
	while (cin>>s)
	{
		//cout<<s<<" asd\n";
		//continue;
		
		palidromo=true;
		espejo=true;
		j=s.size()/2;
		for (i=0; i<j and palidromo; ++i)
			if (s[i]!=s[s.size()-i-1]) palidromo=false;
		
		j++;
		for (i=0; i<j and espejo; ++i)
			if ( s[i]!=arreglo[ s[s.size()-i-1] ] )
				espejo=false;
		//cout<<palidromo<<espejo
		cout<<s;
		if (not palidromo and not espejo)
			{cout<<" -- is not a palindrome.\n";}
		else if (palidromo and not espejo)
			{cout<<" -- is a regular palindrome.\n";}
		else if (not palidromo and espejo)
			{cout<<" -- is a mirrored string.\n";}
		else
			{cout<<" -- is a mirrored palindrome.\n";}
		//cout<<s<<endl;
		cout<<"\n";
	}
	return 0;
}