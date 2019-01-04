#include "guessnum.h"
int li=1, ls, vez=1;
void eval(int n)
{
	//static int li=1, ls, vez=1;
	if (vez) ls=n;
	vez=0;
	int res=(li+ls)/2;
	int p=guess(res);
	if (p==0) 
		answer(res);
	else if (p==-1)
	{
		li=res+1;
		eval(n);
	}
	else
	{
		ls=res-1;
		eval(n);
	}
}
