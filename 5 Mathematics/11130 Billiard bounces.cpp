#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int a, b, v, s, resb, resa;
	double distancia, altura, largura, A;
	//cout<<hypot(50,50)<<endl;
	while (cin>>a>>b>>v>>A>>s and a)
	{
		distancia = v*s/2.0;
		altura = distancia * sin(A*3.14159/180);
		largura = distancia * cos(A*3.14159/180);

		//cout<<A<<endl;
		//cout<<altura<<endl;
		//cout<<largura<<endl<<endl;

		altura -= b/2.0;
		if (altura < 0) resb = 0;
		else
			resb = altura/b +1;

		largura -= a/2.0;
		if (largura < 0) resa = 0;
		else
			resa = largura/a +1;

		cout<<resa<<" "<<resb<<"\n";
	}
	return 0;
}