#include <iostream>
using namespace std;
int main()
{
	int t, contador, i, n, caso=0;
	string s;
	cin>>t;
	while (t--)
	{
		cin>>n;
		cin>>s;
		s.push_back('#');
		s.push_back('#');
		contador=0;
		for (i=0; i<s.size(); ++i)
			if (s[i]=='.')
			{
				++contador;
				i+=2;
			}
		cout<<"Case "<<++caso<<": "<<contador<<endl;
	}
}