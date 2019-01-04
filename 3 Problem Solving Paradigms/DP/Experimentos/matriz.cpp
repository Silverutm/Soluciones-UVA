#include <iostream>
using namespace std;
int matriz[21][21];
int main()
{
	int i, j;
	for (i=0; i<20; ++i)
		for (j=0; j<20; ++j)
		matriz[i][j]=-1;
	for (i=0; i<20; ++i)
	{	
		matriz[i][2]=2;
		matriz[i][18]=6;
	}
	for (i=0; i<20; ++i)
	{	
		matriz[2][i]=4;
		matriz[18][i]=0;
	}
	return 0;
}