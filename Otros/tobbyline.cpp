#include <iostream>
using namespace std;
int main()
{
	double x1, x2, y2, y1;
	while (cin>>x1>>y1>>x2>>y2)
		printf("%lf\n",((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))/6 );
	return 0;
}