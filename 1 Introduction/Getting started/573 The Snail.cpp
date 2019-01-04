#include <iostream>
using namespace std;
int main()
{
	int h, u, d, x;
	double f, dia, noche, sube;
	while (cin>>h>>u>>d>>f, h)
	{
		x=0;
		dia=0;
		noche=0;
		sube=u;
		while (1)
		{
			++x;
			sube=u-u*(x-1)*f/100;
			if (sube<0) sube=0;
			dia+=sube;
			noche=dia-d;
			//cout<<x<<" "<<dia<<" "<<noche<<endl;
			if (dia>h)
			{
				cout<<"success on day "<<x<<endl;
				break;
			}
			else if(noche<0)
			{
				cout<<"failure on day "<<x<<endl;
				break;
			}
			dia=noche;
		}
	}
	return 0;
}