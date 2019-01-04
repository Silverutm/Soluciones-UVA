#include <iostream>
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */
using namespace std;
int azar(int a, int b)
{
	return rand()%b + a;
}

int main()
{
	cout<<1000<<"\n";
	/* initialize random seed: */
  	srand (time(NULL));
  	int a, b,t,w=10;
  	while (w--)
  	{
	  	t=27;
	  	while(t--)
	  	{
	  		a= azar(2,10000000);
	  		while (  ( b=azar(3, 99999990) )<=a  );
	  		cout<<a<<" "<<b<<"\n";
	  	}

	  	t=16;
	  	while(t--)
	  	{
	  		a= azar(2,10);
	  		while (  ( b=azar(3, 999) )<=a  );
	  		cout<<a<<" "<<b<<"\n";
	  	}

	  	t=36;
	  	while(t--)
	  	{
	  		a= azar(2,2);
	  		while (  ( b=azar(3, 999) )<=a  );
	  		cout<<a<<" "<<b<<"\n";
	  	}
	  	t=21;
	  	while(t--)
	  	{
	  		a= azar(2,5);
	  		while (  ( b=azar(3, 9999) )<=a  );
	  		cout<<a<<" "<<b<<"\n";
	  	}
	  }
	return 0;
}