#include <iostream>
using namespace std;
int residuos[7];
int main()
{
	int tot=7;
	int res=20;
	while (tot)
	{
		if (residuos[res%7]==0)
		{
			residuos[res%7]=res;
			--tot;	
		}
		res +=30;
	}
	for ( auto p:residuos)
		cout<<p<<" "<<p/7*7<<endl;
	return 0;
}