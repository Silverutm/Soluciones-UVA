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
ll arreglo[100009];
int main()
{
	int t, i;
	ll n, w, suma;
	cin>>t;
	while (t--)
	{
		cin>>n>>w;
		for (i=0; i<n; ++i)
			cin>>arreglo[i];
		sort(arreglo, arreglo+n);
		suma=0;
		for (i=0; i<n; ++i)
		{
			if (suma+arreglo[i]<=w) suma+=arreglo[i];
			else break;
		}
		cout<<i<<endl;
	}
	return 0;
}