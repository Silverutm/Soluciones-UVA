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
int arreglo[]={0, 115, 3, 4, 9, 7, 37, 8, 19, 13, 121, 14, 45, 20, 35, 36, 41, 23, 103, 21, 61, 24, 81, 62, 49, 27, 212, 34, 77, 31, 364, 78, 222, 43, 87, 82, 412, 139, 209, 241, 117, 44, 97, 98, 91, 72, 309, 118, 127, 59, 165, 1, 2, 76, 381, 57, 161, 114, 169, 65, 277, 63, 143, 85, 170, 191, 240, 86, 297, 144, 159, 73, 298, 92, 192, 79, 153, 95, 438, 105, 197, 96, 198, 89, 371, 256, 272, 133, 750, 195, 384, 93, 217, 99, 218, 250, 329, 334, 244, 102, 234};
int main()
{
	int n;
	while (cin>>n, n)
		cout<<arreglo[n]<<endl;
	return 0;
}