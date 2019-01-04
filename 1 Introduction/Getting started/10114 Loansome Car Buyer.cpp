#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int kd, m, i, j;
	double pago, deuda, carro, depreciaciones[130];
	while (cin>>m and m>0)
	{
		for (i=0; i<=m; ++i)
			depreciaciones[i]=0.0;
		cin>>pago>>deuda>>kd;
		for (i=0; i<kd; ++i)
		{
			cin>>j;
			cin>>depreciaciones[j];
		}
		//for (i=0;i<=m;++i)
		//	cout<<i<<" "<<depreciaciones[i]<<endl;

		for (i=1; i<=m; ++i)
			if (depreciaciones[i]==0.0)
				depreciaciones[i]=depreciaciones[i-1];
				
		
		//for (i=0;i<=m;++i)
		//	cout<<i<<" "<<depreciaciones[i]<<endl;

		carro=deuda+pago;		
		carro *=(1.0-depreciaciones[0]);
		i=0;
		//cout<<carro<<endl;
		//cout<<deuda<<endl;
		//cout<<carro<<" "<<deuda<<endl;
		pago=deuda/m;
		while (carro<=deuda)
		{
			++i;
			deuda-=pago;
			carro*=(1.0-depreciaciones[i]) ;
			//cout<<i<<" "<<carro<<" "<<deuda<<endl;
		}
		if (i==1) printf("1 month\n");
		else printf("%d months\n", i);
	}
	return 0;
}