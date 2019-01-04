#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;
vector <int > v;
int main()
{
	int a, b;
	set <int> miset;
	while (cin>>a)
		miset.insert(a%42);
	cout<<miset.size()<<endl;
	return 0;
}