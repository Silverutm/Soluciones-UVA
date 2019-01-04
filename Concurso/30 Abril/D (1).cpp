#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#define mk make_pair
#define pb push_back()
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair <int, int> ii;
typedef vector < ii > vii;
typedef vector < int > vi;


int arreglo[500];

int main()
{
	
	arreglo['0']=0;
	arreglo['1']=1;
	arreglo['2']=2;
	arreglo['3']=3;
	arreglo['4']=4;
	arreglo['5']=5;
	arreglo['6']=6;
	arreglo['7']=7;
	arreglo['8']=8;
	arreglo['9']=9;
	arreglo['A']=10;
	arreglo['B']=11;
	arreglo['C']=12;
	arreglo['D']=13;
	arreglo['E']=14;
	arreglo['F']=15;
	ll res1, res2, tot;
	string s;
	int i;
	while (cin>>s)
	{
		res2=res1=0;
		for (i=0; i<s.size(); i+=2)
		{
			res1 +=arreglo[ s[i] ];
		}
		for (i=1; i<s.size(); i+=2)
		{
			res2 +=arreglo[ s[i] ];
		}
		tot=res1-res2;
		if (tot%17) printf("no\n");
		else printf("yes\n");
	}
	return 0;
}