#include <iostream>
#include <cstdio>
using namespace std;
string fibo[5009];

string suma(string n1, string n2)
{
	if (n1.size()>n2.size()) n2.resize(n1.size());
	else n1.resize(n2.size());
	string res;
	res.resize( n2.size() );
	int i, lim=n1.size()-1;
	char sum;
	for (i=0; i<lim; ++i)
	{
		sum=n1[i]+n2[i]+res[i];		
		res[i+1]=sum/10;
		res[i]=sum%10;
	}
	sum=n1[i]+n2[i]+res[i];
	res[i]=sum%10;
	if (sum>=10)
		res+=char(sum/10);
	return res;
}

string nachi(int n)
{
	if (fibo[n]!="" )
		return fibo[n];
	return fibo[n]=suma( nachi(n-1), nachi(n-2) );
}

void imprime(string n, int num)
{
	//cout<<n<<endl;
	//cout<<n.size()<<endl;
	//return;
	//cout<<"The Fibonacci number for "<<num<<" is ";
	for (int i=n.size()-1; i>=0; --i)
		printf("%d", n[i]);
	printf("\n");
}

int main()
{
	fibo[0]="1";
	fibo[1]="2";
	fibo[0][0] -='0';
	fibo[1][0] -='0';
	int n;
	while (cin>>n)
		imprime(nachi(n), n);
}