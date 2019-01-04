#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <set>
#define pb push_back
#define mk make_pair
#define f first
#define s second
using namespace std;
typedef pair <int, int> ii;
typedef vector < int > vi;
typedef vector < ii > vii;
typedef long long ll;
string s, arreglo[30];
int valor[300];
int main()
{	
	int sig;
	arreglo[1]="1";
	arreglo[2]="5";
	arreglo[3]="3";
	arreglo[4]="4";
	arreglo[5]="2";
	arreglo[6]="9";
	arreglo[7]="7";
	arreglo[8]="8";
	arreglo[9]="6";
	arreglo[10]="10";
	arreglo[11]="11";
	arreglo[12]="15";
	arreglo[13]="13";
	arreglo[14]="14";
	arreglo[15]="12";
	arreglo[16]="19";
	arreglo[17]="17";
	arreglo[18]="18";
	arreglo[19]="16";
	arreglo[20]="50";
	arreglo[21]="51";
	arreglo[22]="55";
	arreglo[23]="53";
	arreglo[24]="54";
	arreglo[25]="52";
	arreglo[26]="59";
	while (cin>>s)
	{
		sig=1;
		memset(valor, 0,sizeof valor );
		for (auto c:s)
		{
			if (!valor[c])  valor[c]=sig++;
			cout<<arreglo[ valor[c] ];
		}
		cout<<endl;
	}
	return 0;
}