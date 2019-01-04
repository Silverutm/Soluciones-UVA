#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
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
	return ;
}

int gcd(int a, int b)
{
	return b==0 ? a: gcd(b, a%b);
}

int main()
{
	int res, factores[100], cantidad;
	long long n, raiz;
	bool negativo;
	hacerlista();
	while (scanf("%lld", &n)==1, n)
	{		
		//if (n==1){ printf("1\n"); continue;}
		raiz=n;
		negativo=false;
		if (n<0) {n=raiz=-n; negativo=true;}
		raiz=sqrt(raiz);
		cantidad=0;
		memset(factores, 0, sizeof factores);
		for (auto p:primos)
		{
			if (p>raiz)
			{
				if (n!=1 and n!=-1){
				factores[cantidad]=1;
				++cantidad; }
				break;
			}
			if (n%p==0)
			{
				while (n%p==0)
				{
					n/=p;
					++factores[cantidad];
				}
				++cantidad;
			}
		}
		res=factores[0];
		for (int i=1; i<cantidad; ++i)
			res = gcd(res, factores[i]);
		if (negativo and res%2==0)
			while (res%2==0) res /=2;
		//cout<<factores[0]<<endl;
		printf("%d\n", res);
	}
	return 0;
}