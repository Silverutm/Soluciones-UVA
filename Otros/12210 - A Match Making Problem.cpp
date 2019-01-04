#include <iostream>
using namespace std;
int arr[10010];
int b, s, men, i, tot,  k;
int menor()
{
	men=arr[0];
	for(i=0; i<b; ++i)
		if (men>arr[i])
			men=arr[i];

	return men;
}

int main()
{	
	int caso=0;
	while (cin>>b>>s and (b+s) )
	{
		cout<<"Case "<<++caso<<": ";
		for(i=0; i<b; ++i)
			cin>>arr[i];
		for(i=0; i<s; ++i) cin>>k;

		tot = b-s;
		if (tot<0) tot=0;
		if ( tot==0 ) cout<<tot<<endl;
		else cout<<tot<<" "<<menor()<<endl;
	}
	return 0;
}