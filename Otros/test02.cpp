#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int arreglo[20000009];
vector <int> triangulares;
int main()
{
	int i, temp=3*1000009, sum=1, j, n;
	for (i=2; sum<=temp; ++i)
	{
		arreglo[sum]=1;
		triangulares.push_back(sum);
		sum+=i;
	}
	for (j=0; j<triangulares.size(); ++j)
		for (i=j; i<triangulares.size(); ++i)
		{
			sum=triangulares[i]+triangulares[j];
			if (not arreglo[sum])
				arreglo[sum]=2;
		}

	while (scanf("%d", &n)==1)
		if (not arreglo[n])
			printf("3\n");
		else printf("%d\n", arreglo[n]);
	return 0;
}



//bool listo;

/*void f(int k, int is)
{
	if (k==0) 
		if (s%)
}

void sub(int t)
{
	for (k=1; k<=t and not listo; ++k)
		f(k, 0);
}*/
