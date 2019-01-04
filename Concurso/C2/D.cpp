#include <iostream>
#include <cmath>
using namespace std;
double x1, x2, r1, r2, y1, y2, d, A, pi=3.14159;

double distancia()
{
	return sqrt( (x1-x2)*(x1-x2) +(y1-y2)*(y1-y2) );
}

double cosasfeas()
{
	double respuesta=1000;

	return respuesta;
}

int main()
{
	cin>>x1>>y1>>r1;
	cin>>x2>>y2>>r2;
	d=distancia();
	if (r1+r2<=d) A=0;
	else if (d+r2<r1) A=pi*r2*r2;
	else if (d+r1<r2) A=pi*r1*r1;
	else A=cosasfeas();
	return 0;
}