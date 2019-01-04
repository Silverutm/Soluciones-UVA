#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second

using namespace std;

typedef vector <int> vi;
typedef long long ll;
typedef pair <int , int> ii;

string nueves, frente;
void cantidad(int k)
{
	nueves = "";
	while (k--) nueves.pb('9');
}

void adelante(int k)
{
	frente="";
	if (k==1) frente="55";
	else if (k==2) frente="11";
	else if (k==3) frente="66";
	else if (k==4) frente="22";
	else if (k==5) frente="77";
	else if (k==6) frente="33";
	else if (k==7) frente="88";
	else if (k==8) frente="44";	
}

void adelanteimpar(int k)
{
	frente = "";
	if (k==0) frente="1098";
	else if (k==1) frente="64";
	else if (k==2) frente="20";
	else if (k==3) frente="75";
	else if (k==4) frente="31";
	else if (k==5) frente="86";
	else if (k==6) frente="42";
	else if (k==7) frente="97";
	else if (k==8) frente="53";	
}

int main()
{
	int n, k;
	
	//while (scanf("%d", &n) and n)
	//n=1;
	//while ( n<100)
	while (scanf("%d", &n) and n)
	{
		if (n==1 ) printf("-1\n");

		else if (n%2==0)
		{
			k=n/9;
			if (k%2) --k;
			cantidad(k);
			adelante(n%9);
			cout<<frente<<nueves<<"\n";
		}
		else if (n<10)
			printf("-1\n");
		else
		{
			k = n/9;
			if (n%9==0) k-=2;
			else if (k%2 == 0) --k;

			cantidad(k);
			adelanteimpar(n%9);
			cout<<frente<<nueves<<"\n";
		}
		++n;
	}
	return 0;
}