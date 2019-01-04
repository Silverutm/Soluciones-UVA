#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;
#define tam 2000
vector <int> v(4);
set <vector <int > > miset;
int main()
{
	ll a, b, c, d;
	int contador=0;
	for (a=1; a<=tam; ++a)
		for (b=a; b<=tam-a; ++b)
			for (c=b; c<=tam-a-b; ++c)
				//for (d=c; d<=tam-a-b-c; ++d)
				if (a*b*c!=1000000)
				{
					d=1000000*(a+b+c)/(a*b*c-1000000);
					if (d>0 and d<=2000 and a+b+c+d<=2000)
					if (c<=d)
					if ( (a+b+c+d)*1000000==a*b*c*d)
						//cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
					{
						v[0]=a;v[1]=b;v[2]=c; v[3]=d;
						if ( miset.find(v)!=miset.end() ) continue;
						cout<<", "<<a<<", "<<b<<", "<<c<<", "<<d;
						++contador;
						miset.insert(v);
					}
					
				}
	cout<<endl<<endl<<contador<<endl;
	return 0;
}