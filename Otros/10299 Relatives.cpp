#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <bitset>
using namespace std;

vector <int> primos;
bitset <100010> esprimo;
long long limite=100001;
void hacerlista()
{
	esprimo.set();
	esprimo[0]=esprimo[1]=false;
	for (long long i=2; i<=limite; ++i)
		if (esprimo[i])
		{
			for (long long j=i*i; j<=limite; j+=i)
				esprimo[j]=false;
			primos.push_back((int)i);
		}
	return;
}

bool sera(long long n)
{
	if (n<=limite)
		return esprimo[n];
	for (auto v:primos)
		if (n%v==0) return false;
	return true;
}

int main()
{
	hacerlista();
	int n;
	int divisores[100];
	while (scanf("%d", &n), n)
	{
		if (n==1) printf("0\n");
		else
		{
			int i=0, cant=0;
			int res=n, raiz=sqrt(n);
			//while (i<primos.size())
			for (auto p:primos)
			{
				if (p>raiz) break;
				/*if (n%primos[i]==0)
				{
					 ++cant;
					 divisores[cant]=primos[i];
					 n/=primos[i];
				}*/
				if (n%p==0)
				{
					while (n%p==0)
						n/=p;
					res -=res/p;
				}
				//++i;
			}
			if (n>1)
				res-=res/n;
			//if (i!=primos.size())
			//{
			//	++cant;
			//		 divisores[cant]=n;
			//}
			//for (i=1; i<=cant; ++i)
			//	n *=divisores[i]-1;
			//for (i=1; i<=cant; ++i)
			//	res /=divisores[i];
			printf("%d\n", res);
		}
	}
	return 0;
}