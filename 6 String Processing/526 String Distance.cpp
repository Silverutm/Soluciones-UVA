#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
typedef pair <int, int> ii;
int matriz[100][100];
int paps[100][100];
#define diagonal -1
#define izquierda 2
#define arriba 0
int puntos(char a, char b)
{
	if (a==b) return 2;
	return -1;
}
int main()
{
	string w="fsadfsafds";
	string p(w.begin(), w.end());
	cout << p << endl;
	string z(w.begin(), w.begin());
	cout<< z <<endl;
	int aa=0, bb=5;
	aa ^= bb ^= aa ^= bb;
	cout<<aa<<endl<<bb<<endl;
	return 0;
	
	return 0;
}