#include <iostream>
#include <cstdio>
using namespace std;

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

void imprime(string n)
{	
	int i=0;
    while(not n[i]) ++i;
    for ( ; i<n.size(); ++i)
		printf("%d", n[i]);
	printf("\n");
}

int main()
{
	int t;
    string a,b;
    cin>>t;
	while (t--)
    {
        cin>>a>>b;
        for (char &c:a) c-='0';
        for (char &c:b) c-='0';
        imprime( suma(a,b) );
    }
		//imprime(nachi(n), n);
}