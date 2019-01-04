#include <iostream>
#include <cstdlib>     /* srand, rand */
#include <ctime>  
using namespace std;
int main()
{
	srand (time(NULL));
	for (auto k:{32000, 123, 43214,43, 789, 35345,213, 6734})
	{
		cout<<k<<endl;
		int k1=k;
		while (k--)
			cout<<rand()%k1 +1<<" "; 	
		cout<<endl;
	}
	return 0;
}