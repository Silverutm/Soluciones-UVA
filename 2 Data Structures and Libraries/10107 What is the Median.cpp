#include <queue>
#include <iostream>
using namespace std;
priority_queue <int> arribamayor;
priority_queue <int, vector <int>, greater<int> > arribamenor;
int main()
{
	int a;
	bool izquierdo = true;
	while (cin>>a)
	{
		if ( izquierdo )
		{
			if ( arribamayor.empty() )			
				arribamayor.push(a);						

			else if (arribamenor.top()<a)
			{
				arribamayor.push(arribamenor.top());
				arribamenor.pop();
				arribamenor.push(a);
			}
			else arribamayor.push(a);

		}
		else
		{
			if (arribamayor.top()>a)
			{
				arribamenor.push(arribamayor.top());
				arribamayor.pop();
				arribamayor.push(a);
			}
			else arribamenor.push(a);
		}
		izquierdo = not izquierdo;

		if (izquierdo)
			cout<<( arribamenor.top() + arribamayor.top())/2<<endl;
		else cout<<arribamayor.top()<<endl;;
	}
	return 0;
}