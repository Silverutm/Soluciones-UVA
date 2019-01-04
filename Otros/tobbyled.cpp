#include <iostream>
#include <string>
using namespace std;
string s1,s2,s3,s4,s, copia, d;
long long n,t, t2;
long long f(long long i)
{
	long long temp;
	if (d=="R")
	{
		temp=i+2*t;
		//if (temp>=s2.size() ) ++temp;
		return temp%s2.size();
	}
	else
	{
		temp=i-2*t;
		if (temp<1)
		{
			t2=temp/(long long)s2.size();
			t2=temp-t2*(long long)s2.size()+s2.size();
			//t2=1;

			return t2;//%s2.size();	
		}
		return temp;
		
		//if (temp<1)
		//	--temp;
		//while (temp<1) temp+=s2.size();
		//return temp%s2.size();
	}

	 //return (i-2*t + s2.size())%s2.size();
}	

int main()
{
	long long i;
	
	while (cin>>n>>t)
	{
		cin>>d;
		//cout<<n<<endl<<t<<endl<<d<<endl;
		//return 0;
		getline(cin, s);
		getline(cin, s1);
		getline(cin, s2);
		getline(cin, s3);
		s2.pop_back();
		copia=s2;
		for (i=1;i<s2.size(); i+=2)
			copia[f(i)]=s2[i];
		copia+='|';
		cout<<s1<<endl<<copia<<endl<<s3<<endl;
	}
	return 0;
}